// regionImage.h
#ifndef INCLUDED_REGIONIMAGE_H
#define INCLUDED_REGIONIMAGE_H

list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor);

BoundingRectangle* findRegion(int inColumn, int inRow, IplImage* inImage, int inColor);

BoundingRectangle* findRegion(CvPoint inPoint, IplImage* inImage, int inColor);

BoundingRectangle* findRight(int inTop, int inLeft, int inBottom,
                             int inRight, IplImage* inImage, int inColor);

BoundingRectangle* findBottom(int inTop, int inLeft, int inBottom,
                              int inRight, IplImage* inImage, int inColor);

int findBottom(BoundingRectangle* inRectangle, IplImage* inImage, int inColor);
int findRight(BoundingRectangle* inRectangle, IplImage* inImage, int inColor);

#endif

