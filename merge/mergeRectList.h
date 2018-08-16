// mergeRectList.h

#ifndef INCLUDED_MERGE_RECT_LIST_H
#define INCLUDED_MERGE_RECT_LIST_H

list<BoundingRectangle*> combineTouchingRectangles(list<BoundingRectangle*> inRectList, int inTolerance);
list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectList, int inTolerance);

BoundingRectangle* isTouchingRectangle(BoundingRectangle* inRect1,
                                             BoundingRectangle* inRect2,
                                             int inTolerance);

BoundingRectangle*  findCloseRectangle(BoundingRectangle* inRectangle,
                       list<BoundingRectangle*> inRectangleList,
                       int inTolerance);

BoundingRectangle*  findOverlappedByRectangle(BoundingRectangle* inRectangle,
                                              list<BoundingRectangle*> inRectangleList, int tolerance);
list<BoundingRectangle*> getNonOverlappedRectList(list<BoundingRectangle*> inRectangleList, int tolerance);
list<BoundingRectangle*> getTouchingRects(BoundingRectangle* inRectangle,
                                          list<BoundingRectangle*> inRectangleList, int inTolerance);

list<BoundingRectangle*> removeListFromList(list<BoundingRectangle*> inRectangleList,
                                        list<BoundingRectangle*> inRemoveRectList);

#endif

