/*
 * RkRegions.h
 *
 */

#ifndef RKREGIONS_H_
#define RKREGIONS_H_

list<RkBoundingRectangle*> regionizeImage(IplImage* inImage, int inColor);
RkBoundingRectangle* regionBoundary(int inColumn, int inRow, IplImage* inImage, int inColor);

CvPoint getPixel(CvPoint inCurrent, int inPosition);
int getBValue(int n);
int getValidPosition(CvPoint inCurrent, int inPosition);
int findNextPosition(CvPoint inCurrent, int inPosition, IplImage* inImage, int inColor);

#endif /* RKREGIONS_H_ */
