/*
 * RkUtils.h
 *
 */

#ifndef RKUTILS_H_
#define RKUTILS_H_

bool isSamePoint(CvPoint point1, CvPoint point2);
bool isPointBoundByRectangle(CvPoint inPoint, RkBoundingRectangle* inRectangle, int inTolerance);
bool isPointBoundByRectangle(CvPoint inPoint, list<RkBoundingRectangle*> inRectangleList, int inTolerance);

void expandBoundingRectList(list<RkBoundingRectangle*> inRectangleList, int inTimesReduced);


bool isColoredRegion(int inColumn, int inRow, int inRegionSize, IplImage* inImage, int inColor);

IplImage* displayBoundaries(IplImage* inImage, RkBoundingRectangle* inRectangle,
                            CvScalar inColor, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkBoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList, int inSize);


#endif /* RKUTILS_H_ */
