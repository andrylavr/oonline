/*
 * Copyright 1999-2001,2004 The Apache Software Foundation.
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
 * $Id: XMLDOMText.h 191054 2005-06-17 02:56:35Z jberry $
 */

#ifndef ___xmldomtext_h___
#define ___xmldomtext_h___

#include <xercesc/dom/DOMText.hpp>
#include "IXMLDOMTextImpl.h"

XERCES_CPP_NAMESPACE_USE

class ATL_NO_VTABLE CXMLDOMText :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IXMLDOMTextImpl<IXMLDOMText, &IID_IXMLDOMText>
{
public:
	CXMLDOMText()
	{}
	
	void	FinalRelease()
	{
		ReleaseOwnerDoc();
	}

	virtual DOMText* get_DOMText()		 	 { return text;}
	virtual DOMNodeType get_DOMNodeType() const  { return NODE_TEXT; }

DECLARE_NOT_AGGREGATABLE(CXMLDOMText)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CXMLDOMText)
	COM_INTERFACE_ENTRY(IXMLDOMText)
	COM_INTERFACE_ENTRY(IXMLDOMCharacterData)
	COM_INTERFACE_ENTRY(IXMLDOMNode)
	COM_INTERFACE_ENTRY(IIBMXMLDOMNodeIdentity)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
	
	DOMText* text;
};

typedef CComObject<CXMLDOMText> CXMLDOMTextObj;

#endif // ___xmldomtext_h___