// utils.h
#ifndef INCLUDED_UTILS_H
#define INCLUDED_UTILS_H

#define WHITE 0xFF
#define BLACK 0x00

static int BOX_SIZE = 2;

bool isBoundByRectangle(CvPoint inPoint, list<BoundingRectangle*> inRectangleList, int inTolerance);
bool isBoundByRectangle(CvPoint inPoint, BoundingRectangle* inRectangle, int inTolerance);

bool isBlackRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize);
bool isBlackColumn(int inColumn, int inStartRow, int inEndRow, IplImage* inImage);
bool isBlackRow(int inRow, int inStartColumn, int inEndColumn, IplImage* inImage);

bool isWhiteRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize);
bool isWhiteColumn(int inColumn, int inStartRow, int inEndRow, IplImage* inImage);
bool isWhiteRow(int inRow, int inStartColumn, int inEndColumn, IplImage* inImage);

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

static int threshold = 128;
static int tolerance = 1;
static int accuracy = 20;

#endif

