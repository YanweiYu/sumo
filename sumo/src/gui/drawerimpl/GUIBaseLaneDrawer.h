#ifndef GUIBaseLaneDrawer_h
#define GUIBaseLaneDrawer_h
//---------------------------------------------------------------------------//
//                        GUIBaseLaneDrawer.h -
//  Base class for lane drawing;
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Tue, 02.09.2003
//  copyright            : (C) 2003 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
// $Log$
// Revision 1.5  2004/08/02 11:29:37  dkrajzew
// first steps towards user-defined color gradients usage
//
// Revision 1.4  2004/03/19 12:34:30  dkrajzew
// porting to FOX
//
// Revision 1.3  2003/10/02 14:55:56  dkrajzew
// visualisation of E2-detectors implemented
//
// Revision 1.2  2003/09/17 06:45:11  dkrajzew
// some documentation added/patched
//
// Revision 1.1  2003/09/05 14:50:39  dkrajzew
// implementations of artefact drawers moved to folder "drawerimpl"
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include <map>
#include <utils/gfx/RGBColor.h>
#include <gui/GUISUMOAbstractView.h>


/* =========================================================================
 * class declarations
 * ======================================================================= */
class GUILaneWrapper;
class Position2D;


/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * Draws lanes as simple, one-colored straights
 */
class GUIBaseLaneDrawer {
public:
    /// constructor
    GUIBaseLaneDrawer(std::vector<GUIEdge*> &edges);

    /// destructor
    virtual ~GUIBaseLaneDrawer();

    virtual void drawGLLanes(size_t *which, size_t maxEdges,
        double width, GUISUMOAbstractView::LaneColoringScheme scheme);

    void setUseExponential(bool val);

protected:
    /// initialises the drawing
    virtual void initStep();

    /// draws a single vehicle
    virtual void drawLane(const GUILaneWrapper &lane,
        GUISUMOAbstractView::LaneColoringScheme scheme, double width) = 0;

    /// sets the colour of the vehicle to draw
    virtual void setLaneColor(const GUILaneWrapper &lane,
        GUISUMOAbstractView::LaneColoringScheme scheme);

protected:
    /// The list of edges to consider at drawing
    std::vector<GUIEdge*> &myEdges;

    /// The gradient used
    static std::vector<RGBColor> myDensityGradient;

private:
    bool myUseExponential;

};


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

#endif

// Local Variables:
// mode:C++
// End:

