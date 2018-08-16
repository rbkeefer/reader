/*
 * RkSize.h
 *

 */

#ifndef RKSIZE_H_
#define RKSIZE_H_

list<RkColumn*> findColumns(IplImage* inImage, int inMinHeight, int inColor);

IplImage* reduceImage(IplImage* inImage, int inWidth, int inDemoMode);
IplImage* reduceImage(IplImage* inImage);

IplImage* expandImage(IplImage* inImage, int inWidth);
IplImage* expandImage(IplImage* inImage);

#endif /* RKSIZE_H_ */
