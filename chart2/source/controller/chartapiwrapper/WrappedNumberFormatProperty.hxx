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


#ifndef CHART2_WRAPPEDNUMBERFORMATPROPERTY_HXX
#define CHART2_WRAPPEDNUMBERFORMATPROPERTY_HXX

#include "WrappedDirectStateProperty.hxx"
#include "Chart2ModelContact.hxx"

#include <boost/shared_ptr.hpp>

//.............................................................................
namespace chart
{
namespace wrapper
{
//.............................................................................

class WrappedLinkNumberFormatProperty;

class WrappedNumberFormatProperty : public WrappedDirectStateProperty
{
public:
    WrappedNumberFormatProperty( ::boost::shared_ptr< Chart2ModelContact > spChart2ModelContact );
    virtual ~WrappedNumberFormatProperty();

    virtual void setPropertyValue( const ::com::sun::star::uno::Any& rOuterValue, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySet >& xInnerPropertySet ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::beans::PropertyVetoException, ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Any getPropertyValue( const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySet >& xInnerPropertySet ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Any getPropertyDefault( const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertyState >& xInnerPropertyState ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    friend class WrappedLinkNumberFormatProperty;
private:
    ::boost::shared_ptr< Chart2ModelContact >   m_spChart2ModelContact;
    mutable ::com::sun::star::uno::Any m_aOuterValue;
    WrappedLinkNumberFormatProperty* m_pWrappedLinkNumberFormatProperty;
};

class WrappedLinkNumberFormatProperty : public WrappedProperty
{
public:
    WrappedLinkNumberFormatProperty( WrappedNumberFormatProperty* pWrappedNumberFormatProperty );
    virtual ~WrappedLinkNumberFormatProperty();

    virtual void setPropertyValue( const ::com::sun::star::uno::Any& rOuterValue, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySet >& xInnerPropertySet ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::beans::PropertyVetoException, ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Any getPropertyValue( const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySet >& xInnerPropertySet ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    virtual ::com::sun::star::uno::Any getPropertyDefault( const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertyState >& xInnerPropertyState ) const
                        throw (::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException);

    friend class WrappedNumberFormatProperty;
private:
    WrappedNumberFormatProperty* m_pWrappedNumberFormatProperty;
};

//.............................................................................
} //namespace wrapper
} //namespace chart
//.............................................................................

// CHART2_WRAPPEDNUMBERFORMATPROPERTY_HXX
#endif
