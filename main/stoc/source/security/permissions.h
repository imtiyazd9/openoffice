/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


#ifndef _STOC_SEC_PERMISSIONS_H_
#define _STOC_SEC_PERMISSIONS_H_

#include <rtl/unload.h>
#include <rtl/ref.hxx>
#include <rtl/ustring.hxx>
#include <salhelper/simplereferenceobject.hxx>

#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>

extern ::rtl_StandardModuleCount g_moduleCount;

namespace stoc_sec
{
//==================================================================================================
class Permission : public ::salhelper::SimpleReferenceObject
{
public:    
    ::rtl::Reference< Permission > m_next;
    // mode
    enum t_type { ALL, RUNTIME, SOCKET, FILE } m_type;
    
    inline Permission(
        t_type type,
        ::rtl::Reference< Permission > const & next = ::rtl::Reference< Permission >() )
        SAL_THROW( () )
        : m_next( next )
        , m_type( type )
        {}
    
    virtual bool implies( Permission const & perm ) const SAL_THROW( () ) = 0;
    virtual ::rtl::OUString toString() const SAL_THROW( () ) = 0;
};
//==================================================================================================
class AllPermission : public Permission
{
public:
    inline AllPermission(
        ::rtl::Reference< Permission > const & next = ::rtl::Reference< Permission >() )
        SAL_THROW( () )
        : Permission( ALL, next )
        {}
    
    virtual bool implies( Permission const & ) const SAL_THROW( () );
    virtual ::rtl::OUString toString() const SAL_THROW( () );
};

//==================================================================================================
class PermissionCollection
{
    ::rtl::Reference< Permission > m_head;
public:
    inline PermissionCollection() SAL_THROW( () )
        {}
    inline PermissionCollection( PermissionCollection const & collection ) SAL_THROW( () )
        : m_head( collection.m_head )
        {}
    inline PermissionCollection( ::rtl::Reference< Permission > const & single ) SAL_THROW( () )
        : m_head( single )
        {}
    PermissionCollection(
        ::com::sun::star::uno::Sequence< ::com::sun::star::uno::Any > const & permissions,
        PermissionCollection const & addition = PermissionCollection() )
        SAL_THROW( (::com::sun::star::uno::RuntimeException) );
#ifdef __DIAGNOSE
    ::com::sun::star::uno::Sequence< ::rtl::OUString > toStrings() const SAL_THROW( () );
#endif    
    void checkPermission( ::com::sun::star::uno::Any const & perm ) const
        SAL_THROW( (::com::sun::star::uno::RuntimeException) );
};

}

#endif
