// utils.h
#ifndef INCLUDED_UTILS_H
#define INCLUDED_UTILS_H

#define WHITE 0xFF
#define BLACK 0x00

static int BOX_SIZE = 2;

bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor);
bool isColoredColumn(int inColumn, int inStartRow, int inEndRow, IplImage* inImage, int inColor);
bool isColoredRow(int inColumn, int inStartRow, int inEndRow, IplImage* inImage, int inColor);

bool isBoundByRectangle(CvPoint inPoint, list<BoundingRectangle*> inRectangleList, int inTolerance);
bool isBoundByRectangle(CvPoint inPoint, BoundingRectangle* inRectangle, int inTolerance);

bool isIn(int inX, int inY, BoundingRectangle* inRectangle, int inTolerance);
bool isNear(int point1, int point2, int tolerance);

list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectangleList, int inTolerance);
list<BoundingRectangle*> eliminateOverlaps(list<BoundingRectangle*> inRectangleList, int inTolerance);

bool sameRectangle(BoundingRectangle* first, BoundingRectangle* second);
bool compareTopLeft(BoundingRectangle* first, BoundingRectangle* second);

BoundingRectangle* combineRectangles(BoundingRectangle* rect1, BoundingRectangle* rect2);
void dumpRectList(list<BoundingRectangle*> rectList);

static int threshold = 128;
static int tolerance = 1;
static int accuracy = 20;

#endif

