/*
 * RkUtils.h
 *
 */

#ifndef RKUTILS_H_
#define RKUTILS_H_

bool isSamePoint(CvPoint point1, CvPoint point2);
bool isPointBoundByRectangle(CvPoint inPoint, RkBoundingRectangle* inRectangle, int inTolerance);
bool isPointBoundByRectangle(CvPoint inPoint, list<RkBoundingRectangle*> inRectangleList, int inTolerance);
bool isRectangleInRectangleList(RkBoundingRectangle* inSegment, list<RkBoundingRectangle*> inSegmentList);
bool isColoredRegion(int inColumn, int inRow, int inRegionSize, IplImage* inImage, int inColor);
bool isSimilarHeight(RkBoundingRectangle* inRect1, RkBoundingRectangle* inRect2, int inTolerance);
bool isSegmentInSegmentList(RkSegment* inSegment, list<RkSegment*> inSegmentList);
bool isArticleInArticleList(RkArticle* inArticle, list<RkArticle*> inArticleList);

RkSegment* getLargestSegment(list<RkSegment*> inSegmentList);
list<RkSegment*> getTypedSegments(list<RkSegment*> inSegmentList, int inType);

void expandBoundingRectList(list<RkBoundingRectangle*> inRectangleList, int inTimesReduced);

IplImage* displayBoundaries(IplImage* inImage, RkBoundingRectangle* inRectangle,
                            CvScalar inColor, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkBoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList, int inSize);

IplImage* displayBoundaries(IplImage* inImage, list<RkArticle*> inArticleList, int inSize);


#endif /* RKUTILS_H_ */
