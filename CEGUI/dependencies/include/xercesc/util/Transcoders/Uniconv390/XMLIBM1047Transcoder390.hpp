/*
 * Copyright 2004,2004 The Apache Software Foundation.
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
 * $Id: XMLIBM1047Transcoder390.hpp 191054 2005-06-17 02:56:35Z jberry $
 */

#ifndef XMLIBM1047TRANSCODER390_HPP
#define XMLIBM1047TRANSCODER390_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/Transcoders/Uniconv390/XML256TableTranscoder390.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
//  This class provides an implementation of the XMLTranscoder interface
//  for a simple 1047-US transcoder. The parser does some encodings
//  intrinsically without depending upon external transcoding services.
//  To make everything more orthagonal, we implement these internal
//  transcoders using the same transcoder abstraction as the pluggable
//  transcoding services do.
//
//
class XMLUTIL_EXPORT XMLIBM1047Transcoder390 : public XML256TableTranscoder390
{
public :
    // -----------------------------------------------------------------------
    //  Public, static methods
    // -----------------------------------------------------------------------
    static XMLCh xlatThisOne(const XMLByte toXlat);


    // -----------------------------------------------------------------------
    //  Public constructors and destructor
    // -----------------------------------------------------------------------
    XMLIBM1047Transcoder390
    (
        const   XMLCh* const    encodingName
        , const unsigned int    blockSize
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    virtual ~XMLIBM1047Transcoder390();


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLIBM1047Transcoder390();
    XMLIBM1047Transcoder390(const XMLIBM1047Transcoder390&);
    void operator=(const XMLIBM1047Transcoder390&);
};

XERCES_CPP_NAMESPACE_END

#endif
