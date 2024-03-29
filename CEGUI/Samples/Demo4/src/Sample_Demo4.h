/***********************************************************************
    filename:   Sample_Demo4.h
    created:    20/8/2005
    author:     Paul D Turner
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
#ifndef _Sample_Demo4_h_
#define _Sample_Demo4_h_

#include "CEGuiSample.h"
#include "CEGUI.h"

// Sample class
class Demo4Sample : public CEGuiSample
{
public:
    // method to initialse the samples windows and events.
    bool initialiseSample();

    // method to perform any required cleanup operations.
    void cleanupSample(void);

    /*************************************************************************
        member functions used as event handlers
    *************************************************************************/
    bool handleQuit(const CEGUI::EventArgs& e);
    bool horzMoveHandler(const CEGUI::EventArgs& e);
    bool vertMoveHandler(const CEGUI::EventArgs& e);
    bool vscrollHandler(const CEGUI::EventArgs& e);
};

// some free functions used as event handlers
bool sliderHandler(const CEGUI::EventArgs& e);
bool formatChangedHandler(const CEGUI::EventArgs& e);
bool textChangedHandler(const CEGUI::EventArgs& e);

#endif  // end of guard _Sample_Demo4_h_
