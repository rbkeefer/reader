// regionImage.h
#ifndef INCLUDED_REGIONIMAGE_H
#define INCLUDED_REGIONIMAGE_H

list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor);
BoundingRectangle* findRegion(CvPoint inPoint, IplImage* inImage, int inColor);

#endif

