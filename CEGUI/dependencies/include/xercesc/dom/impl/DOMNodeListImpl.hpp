#ifndef DOMNodeListImpl_HEADER_GUARD_
#define DOMNodeListImpl_HEADER_GUARD_
/*
 * Copyright 2001-2002,2004 The Apache Software Foundation.
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
 * $Id: DOMNodeListImpl.hpp 176026 2004-09-08 13:57:07Z peiyongz $
 */

//
//  This file is part of the internal implementation of the C++ XML DOM.
//  It should NOT be included or used directly by application programs.
//
//  Applications should include the file <xercesc/dom/DOM.hpp> for the entire
//  DOM API, or xercesc/dom/DOM*.hpp for individual DOM classes, where the class
//  name is substituded for the *.
//


//  NodeList implementation class -
//     This is for NodeLists returned by GetChildNodes only, not for
//     node lists returned by GetElementsByTagName
//
//     Every node type capable of having children has (as an embedded member)
//     an instance of this class.  To hold down the size overhead on each node, a
//     cache of extended data for active node lists is maintained
//     separately.
//

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOMNodeList.hpp>

XERCES_CPP_NAMESPACE_BEGIN


class DOMNode;

class CDOM_EXPORT DOMNodeListImpl: public DOMNodeList
{
private:
    DOMNode   *fNode;

    // Unused, and unimplemented constructors, operators, etc.
    DOMNodeListImpl();
    DOMNodeListImpl(const DOMNodeListImpl & other);
    DOMNodeListImpl & operator = (const DOMNodeListImpl & other);

public:
    DOMNodeListImpl(DOMNode *node);
    virtual             ~DOMNodeListImpl();
    virtual DOMNode *  item(XMLSize_t index) const;
    virtual XMLSize_t getLength() const;
};

XERCES_CPP_NAMESPACE_END

#endif


