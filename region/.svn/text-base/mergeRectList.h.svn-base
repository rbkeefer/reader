// mergeRectList.h

#ifndef INCLUDED_MERGE_RECT_LIST_H
#define INCLUDED_MERGE_RECT_LIST_H

#include <list>
#include "BoundingRectangle.h"

using namespace std;

list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectangleList, int inTolerance);
list<BoundingRectangle*> eliminateOverlaps(list<BoundingRectangle*> inRectangleList);

list<BoundingRectangle*> getSeparatedRectList(list<BoundingRectangle*> inRectangleList,
                                              int inTolerance);
BoundingRectangle*  findCloseRectangle(BoundingRectangle* inRectangle,
                       list<BoundingRectangle*> inRectangleList,
                       int inTolerance);

BoundingRectangle*  findOverlappedByRectangle(BoundingRectangle* inRectangle, list<BoundingRectangle*> inRectangleList);
list<BoundingRectangle*> getNonOverlappedRectList(list<BoundingRectangle*> inRectangleList);

#endif

