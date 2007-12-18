/***********************************************************************
	filename: 	FalStaticProperties.h
	created:	Sat Sep 17 2005
	author:		Tomas Lindquist Olsen (based on code by Paul D Turner)
	
	purpose:	Interface to properties for FalagardStatic (base class) widget.
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _FalagardStaticProperties_h_
#define _FalagardStaticProperties_h_

#include "CEGUIProperty.h"

// Start of CEGUI namespace section
namespace CEGUI
{

// Start of FalagardStaticProperties namespace section
/*!
\brief
	Namespace containing all classes that make up the properties interface for the FalagardStatic (base) class
*/
namespace FalagardStaticProperties
{

/*!
\brief
	Property to access the state of the frame enabled setting for the FalagardStatic widget.

	\par Usage:
		- Name: FrameEnabled
		- Format: "[text]".

	\par Where [Text] is:
		- "True" to indicate that the frame is enabled.
		- "False" to indicate that the frame is disabled.
*/
class FrameEnabled : public Property
{
public:
	FrameEnabled() : Property(
		"FrameEnabled",
		"Property to get/set the state of the frame enabled setting for the FalagardStatic widget.  Value is either \"True\" or \"False\".",
		"True")
	{}

	String	get(const PropertyReceiver* receiver) const;
	void	set(PropertyReceiver* receiver, const String& value);
};


/*!
\brief
	Property to access the state of the frame background setting for the FalagardStatic widget.

	\par Usage:
		- Name: BackgroundEnabled
		- Format: "[text]".

	\par Where [Text] is:
		- "True" to indicate that the background is enabled.
		- "False" to indicate that the background is disabled.
*/
class BackgroundEnabled : public Property
{
public:
	BackgroundEnabled() : Property(
		"BackgroundEnabled",
		"Property to get/set the state of the frame background setting for the FalagardStatic widget.  Value is either \"True\" or \"False\".",
		"True")
	{}

	String	get(const PropertyReceiver* receiver) const;
	void	set(PropertyReceiver* receiver, const String& value);
};

} // End of  FalagardStaticProperties namespace section

} // End of  CEGUI namespace section


#endif	// end of guard _FalagardStaticProperties_h_
