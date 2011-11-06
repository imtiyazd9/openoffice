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



#ifndef _CHART2_CREATION_TYPE_UNO_HXX
#define _CHART2_CREATION_TYPE_UNO_HXX

#include "ServiceMacros.hxx"
#include <com/sun/star/awt/XWindow.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <vcl/vclevent.hxx>

#include <svtools/genericunodialog.hxx>
//.............................................................................
namespace chart
{
//.............................................................................
typedef ::svt::OGenericUnoDialog ChartTypeUnoDlg_BASE;
class ChartType;
class ChartTypeUnoDlg : public ChartTypeUnoDlg_BASE
                        ,public ::comphelper::OPropertyArrayUsageHelper< ChartTypeUnoDlg >
{
public:
    ChartTypeUnoDlg( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext >& xContext );

    // XServiceInfo - static methods
	static ::com::sun::star::uno::Sequence< ::rtl::OUString > getSupportedServiceNames_Static(void);
	static ::rtl::OUString getImplementationName_Static(void) throw( ::com::sun::star::uno::RuntimeException );
	static ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface >
			SAL_CALL Create(const ::com::sun::star::uno::Reference< com::sun::star::uno::XComponentContext >&);
private:
    virtual ~ChartTypeUnoDlg();

    // OGenericUnoDialog overridables
	virtual void implInitialize(const com::sun::star::uno::Any& _rValue);
    virtual Dialog*	createDialog(Window* _pParent);

    // XTypeProvider
    virtual com::sun::star::uno::Sequence<sal_Int8> SAL_CALL getImplementationId(  ) throw(com::sun::star::uno::RuntimeException);
    // XServiceInfo
	virtual ::rtl::OUString SAL_CALL getImplementationName() throw(::com::sun::star::uno::RuntimeException);
	virtual ::comphelper::StringSequence SAL_CALL getSupportedServiceNames() throw(::com::sun::star::uno::RuntimeException);

    // XPropertySet
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySetInfo>  SAL_CALL getPropertySetInfo() throw(::com::sun::star::uno::RuntimeException);
	virtual ::cppu::IPropertyArrayHelper& SAL_CALL getInfoHelper();

	// OPropertyArrayUsageHelper
	virtual ::cppu::IPropertyArrayHelper* createArrayHelper( ) const;

    //no default constructor
    ChartTypeUnoDlg();
    ChartTypeUnoDlg(const ChartTypeUnoDlg&); // no defined
    void operator =(const ChartTypeUnoDlg&); // no defined
    
    ::com::sun::star::uno::Reference< ::com::sun::star::frame::XModel >           m_xChartModel;
};

//.............................................................................
} //namespace chart
//.............................................................................
#endif
