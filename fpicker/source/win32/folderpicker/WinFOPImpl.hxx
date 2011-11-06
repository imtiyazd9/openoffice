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




#ifndef _WINFOPIMPL_HXX_
#define _WINFOPIMPL_HXX_


//------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------

#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include "MtaFop.hxx"

//------------------------------------------------------------------------
// forward 
//------------------------------------------------------------------------

class CFolderPicker;

//------------------------------------------------------------------------
// deklarations
//------------------------------------------------------------------------

class CWinFolderPickerImpl : public CMtaFolderPicker
{
public:
	CWinFolderPickerImpl( CFolderPicker* aFolderPicker );
		
	//-----------------------------------------------------------------------------------------
	// XExecutableDialog
	//-----------------------------------------------------------------------------------------
	
    virtual sal_Int16 SAL_CALL execute(  ) 
		throw( com::sun::star::uno::RuntimeException );

	//-----------------------------------------------------
	// XFolderPicker 
	//-----------------------------------------------------

	virtual void SAL_CALL setDisplayDirectory( const rtl::OUString& aDirectory )
		throw( com::sun::star::lang::IllegalArgumentException, com::sun::star::uno::RuntimeException );

	virtual rtl::OUString SAL_CALL getDisplayDirectory( )
		throw( com::sun::star::uno::RuntimeException );

    virtual rtl::OUString SAL_CALL getDirectory( )
        throw( com::sun::star::uno::RuntimeException );

protected:
	virtual void SAL_CALL onSelChanged( const rtl::OUString& aNewPath );
	
private:
	CFolderPicker*	m_pFolderPicker;	
	sal_Int16		m_nLastDlgResult;	
};

#endif
