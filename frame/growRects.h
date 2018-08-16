// growRects.h

#ifndef INCLUDED_GROW_RECTS_H
#define INCLUDED_GROW_RECTS_H

list<BoundingRectangle*> growRectangles(IplImage* inImage,
                                        list<BoundingRectangle*> inRectList,
                                        int inTolerance, int inColor);

BoundingRectangle* growRectangleHeight(IplImage* inImage,
                                 BoundingRectangle* inRectangle,
                                 int inTolerance, int inColor);

#endif

