/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: XMLDOMImplementation.h 191054 2005-06-17 02:56:35Z jberry $
 */

#ifndef ___xmldomimplementation_h___
#define ___xmldomimplementation_h___

#include <xercesc/dom/DOMImplementation.hpp>

XERCES_CPP_NAMESPACE_USE

class ATL_NO_VTABLE CXMLDOMImplementation : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IXMLDOMImplementation, &IID_IXMLDOMImplementation, &LIBID_Xerces, XERCES_VERSION_MAJOR, INVK_CAT2_RAW_NUMERIC(XERCES_VERSION_MINOR,XERCES_VERSION_REVISION)>
{
public:
	CXMLDOMImplementation()
	{}

DECLARE_NOT_AGGREGATABLE(CXMLDOMImplementation)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CXMLDOMImplementation)
	COM_INTERFACE_ENTRY(IXMLDOMImplementation)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	// IXMLDOMImplementation methods
	STDMETHOD(hasFeature)(BSTR feature, BSTR ver, VARIANT_BOOL  *pVal);

	DOMImplementation* implementation;
};

typedef CComObject<CXMLDOMImplementation> CXMLDOMImplementationObj;

#endif // ___xmldomimplemenation_h___
