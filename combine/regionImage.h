// regionImage.h
#ifndef INCLUDED_REGIONIMAGE_H
#define INCLUDED_REGIONIMAGE_H


/***  Row/Column approach  ***/
list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor,
                                        list<ColumnLine*> inColumnLines,
                                        list<RowLine*> inRowLines);

BoundingRectangle* rectFromLines(int inColumn, int inRow,
                                 list<ColumnLine*> inColumnLines, list<RowLine*> inRowLines);

int findTop(int inColumn, int inRow, list<RowLine*> inRowLines);
int findBottom(int inColumn, int inRow, list<RowLine*> inRowLines);
int findLeft(int inColumn, int inRow, list<ColumnLine*> inColumnLines);
int findRight(int inColumn, int inRow, list<ColumnLine*> inColumnLines);


/***  Pixel-based approaches  ***/

list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor);

BoundingRectangle* simpleSearch(int inColumn, int inRow, IplImage* inImage, int inColor);

BoundingRectangle* angularSearch(CvPoint inPoint, IplImage* inImage, int inColor);
BoundingRectangle* findRight(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor);
BoundingRectangle* findBottom(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor);

BoundingRectangle* nearestNeighbor(int inColumn, int inRow, IplImage* inImage, int inColor);
int nnFindTop(int inColumn, int inRow, IplImage* inImage, int inColor);
int nnFindBottom(int inColumn, int inRow, IplImage* inImage, int inColor);
int nnFindLeft(int inColumn, int inRow, IplImage* inImage, int inColor);
int nnFindRight(int inColumn, int inRow, IplImage* inImage, int inColor);

#endif

