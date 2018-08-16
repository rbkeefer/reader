// combineTouchingRects.h

#ifndef INCLUDED_COMBINE_RECTS_H
#define INCLUDED_COMBINE_RECTS_H

list<BoundingRectangle*> combineRectangles(list<BoundingRectangle*> inRectList,
                                                   int inTolerance);

list<BoundingRectangle*> combineSimilarRects(list<BoundingRectangle*> inRectList,
                                           int inTolerance);

list<BoundingRectangle*> getRectsToCombine(BoundingRectangle* inRectangle,
                                          list<BoundingRectangle*> inRectangleList, int inTolerance);

BoundingRectangle* isSimilarRectangle(BoundingRectangle* inRect1,
                                       BoundingRectangle* inRect2,
                                       int inTolerance);

#endif

