/*
 * RkRow.cpp
 *
 */

#include "Segment.h"
#include "RkRow.h"

RkRow::RkRow() {
    left = 0;
    right = 0;
    row = 0;
}

RkRow::RkRow(int inRow, int inLeft, int inRight)
{
  left = inLeft;
  right = inRight;
  row = inRow;
}

RkRow::~RkRow() {
	// Do Nothing for now
}

CvPoint RkRow::leftPoint()
{
  CvPoint point;
  point.x = left;
  point.y = row;

  return point;
}

CvPoint RkRow::rightPoint()
{
  CvPoint point;
  point.x = right;
  point.y = row;

  return point;
}

int RkRow::width()
{
  return right-left;
}

bool RkRow::pointIn(int inColumn, int inRow, int inTolerance)
{
  if (inRow == row)
  {
    if ((inColumn >= left-inTolerance) && (inColumn <= right+inTolerance))
      return true;
  }

  return false;
}

bool RkRow::equals(RkRow* inLine)
{
  if (left != inLine->left) return false;
  if (right != inLine->right) return false;
  if (row != inLine->row) return false;

  return true;
}

void RkRow::toString()
{
  printf("RowLine: left[%d] right[%d] row[%d]\n",
         left, right, row);
}
