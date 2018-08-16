// findParts.h
#ifndef INCLUDED_FINDPARTS_H
#define INCLUDED_FINDPARTS_H

#include "ColumnLine.h"
#include "RowLine.h"

list<ColumnLine*> findColumns(IplImage* inImage, int inColor);
list<RowLine*> findRows(IplImage* inImage, int inColor);


list<ColumnLine*> accelerateColumns(IplImage* inImage,
                  list<ColumnLine*> inColumnList,
                  list<RowLine*> inRowList,
                  int inColor);

list<RowLine*> accelerateRows(IplImage* inImage,
               list<ColumnLine*> inColumnList,
               list<RowLine*> inRowList,
               int inColor);

#endif

