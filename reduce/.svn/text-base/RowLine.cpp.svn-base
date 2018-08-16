#include "pyramid.h"
#include "RowLine.h"

RowLine::RowLine()
{
  left = 0;
  right = 0;
  row = 0;
}

RowLine::RowLine(int inRow, int inLeft, int inRight)
{
  left = inLeft;
  right = inRight;
  row = inRow;
}

CvPoint RowLine::leftPoint()
{
  CvPoint point;
  point.x = left;
  point.y = row;

  return point;
}

CvPoint RowLine::rightPoint()
{
  CvPoint point;
  point.x = right;
  point.y = row;

  return point;
}

int RowLine::width()
{
  return right-left;
}

bool RowLine::pointIn(int inColumn, int inRow, int inTolerance)
{
  if (inRow == row)
  {
    if ((inColumn >= left-inTolerance) && (inColumn <= right+inTolerance))
      return true;
  }

  return false;
}

bool RowLine::equals(RowLine* inLine)
{
  if (left != inLine->left) return false;
  if (right != inLine->right) return false;
  if (row != inLine->row) return false;

  return true;
}

void RowLine::toString()
{
  printf("RowLine: left[%d] right[%d] row[%d]\n",
         left, right, row);
}


