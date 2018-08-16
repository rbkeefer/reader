// utils.h
#ifndef INCLUDED_UTILS_H
#define INCLUDED_UTILS_H

bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor);
bool isColoredColumn(int inColumn, int inStartRow, int inEndRow, IplImage* inImage, int inColor);
bool isColoredRow(int inColumn, int inStartRow, int inEndRow, IplImage* inImage, int inColor);

bool isBoundByRectangle(CvPoint inPoint, list<BoundingRectangle*> inRectangleList, int inTolerance);
bool isBoundByRectangle(CvPoint inPoint, BoundingRectangle* inRectangle, int inTolerance);

bool isIn(int inX, int inY, BoundingRectangle* inRectangle, int inTolerance);
bool isNear(int point1, int point2, int tolerance);
bool isRectangleInList(BoundingRectangle* inRectangle, list<BoundingRectangle*> inRectangleList);

list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectangleList, int inTolerance);
list<BoundingRectangle*> eliminateOverlaps(list<BoundingRectangle*> inRectangleList, int inTolerance);

bool sameRectangle(BoundingRectangle* first, BoundingRectangle* second);
bool compareTopLeft(BoundingRectangle* first, BoundingRectangle* second);

BoundingRectangle* combineRectangles(BoundingRectangle* rect1, BoundingRectangle* rect2);
BoundingRectangle* combineRectList(BoundingRectangle* inRectangle, list<BoundingRectangle*> inRectangleList);

void dumpRectList(list<BoundingRectangle*> rectList);
void dumpRectCode(list<BoundingRectangle*> rectList);

#endif

