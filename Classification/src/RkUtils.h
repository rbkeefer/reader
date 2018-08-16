/*
 * RkUtils.h
 *
 */

#ifndef RKUTILS_H_
#define RKUTILS_H_

bool isSamePoint(CvPoint point1, CvPoint point2);
bool isBoundByRectangle(CvPoint inPoint, RkBoundingRectangle* inRectangle, int inTolerance);
bool isBoundByRectangle(CvPoint inPoint, list<RkBoundingRectangle*> inRectangleList, int inTolerance);

void expandBoundingRectList(list<RkBoundingRectangle*> inRectangleList, int inTimesReduced);


bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor);

IplImage* displayBoundaries(IplImage* inImage, list<RkBoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList, int inSize);

bool compareTextFrameTopLeft(RkTextFrame* first, RkTextFrame* second);
bool compareTextFrameBottomRight(RkTextFrame* first, RkTextFrame* second);
bool sameTextFrame(RkTextFrame* first, RkTextFrame* second);

#endif /* RKUTILS_H_ */
