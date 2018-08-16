/*
 * RkBoundingRectangle.h
 *
 */

#ifndef RKBOUNDINGRECTANGLE_H_
#define RKBOUNDINGRECTANGLE_H_

#include <string>
#include "/opt/local/include/opencv/cv.h"
#include "/opt/local/include/opencv/cvaux.h"
#include "/opt/local/include/opencv/highgui.h"

#include <list>
using namespace std;

class RkBoundingRectangle {
public:
	RkBoundingRectangle();
    RkBoundingRectangle(int inTop, int inLeft, int inBottom, int inRight);
    RkBoundingRectangle(RkBoundingRectangle* inRectangle);
	virtual ~RkBoundingRectangle();

    int top, bottom, left, right;

    CvPoint topLeft();
    CvPoint bottomLeft();
    CvPoint topRight();
    CvPoint bottomRight();

    bool isPointIn(int inColumn, int inRow, int inTolerance=0);
    bool isRectIn(RkBoundingRectangle* inRect);

    bool equals(RkBoundingRectangle* inRect);

    bool isNear(RkBoundingRectangle* inRect, int inTolerance=0);
    bool isAbove(RkBoundingRectangle* inRect, int inTolerance=0);
    bool isBelow(RkBoundingRectangle* inRect, int inTolerance=0);
    bool isVerticalOverlap(RkBoundingRectangle* inRect);

    bool isColumnShape();
    bool isRowShape();

    int area();
    int width();
    int height();

    void move(CvPoint topLeft);
    void join(RkBoundingRectangle*);

    CvRect toRect();
    void toString();
    void printString(FILE* inFile);
};

#endif /* RKBOUNDINGRECTANGLE_H_ */
