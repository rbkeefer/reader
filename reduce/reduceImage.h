// reduceImage.h
#ifndef INCLUDED_REDUCEIMAGE_H
#define INCLUDED_REDUCEIMAGE_H

IplImage* reduceImage(IplImage* inImage);
IplImage* expandImage(IplImage* inImage);

IplImage* cleanReducedImage(IplImage* inImage, list<ColumnLine*> inColumnList,
                            list<RowLine*> inRowList, int inColor);

bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor);

#endif

