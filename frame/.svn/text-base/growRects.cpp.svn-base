#include "pyramid.h"
#include "utils.h"
#include "BoundingRectangle.h"
#include "growRects.h"

list<BoundingRectangle*> growRectangles(IplImage* inImage,
                                           list<BoundingRectangle*> inRectangleList,
                                           int inTolerance, int inColor)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* newRectangle;

  printf("Grow Rectangles ...\n");

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    newRectangle = growRectangleHeight(inImage, (*iter), inTolerance, inColor);
    returnList.push_back(newRectangle);
  }

  return returnList;
}

BoundingRectangle* growRectangleHeight(IplImage* inImage,
                                 BoundingRectangle* inRectangle,
                                 int inTolerance, int inColor)
{
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int left = inRectangle->left;
  int right = inRectangle->right;
  int top = inRectangle->top;
  int bottom = inRectangle->bottom;
  int upperLimit = (top-inTolerance < 0) ? 0 : top-inTolerance;
  int lowerLimit = (bottom+inTolerance > imageHeight) ? imageHeight : bottom+inTolerance;
  int newTop = top;
  int newBottom = bottom;
  int column;
  int row;

  row = top;
  while (row > 0)
  {
    row--;
    for(column=left; column<right; column++)
    {
      if (isColoredRegion(column, row, inImage, 1, inColor))
      {
        newTop = row;
        break;
      }
    }
    if (column == right) break;
  }

  row = bottom;
  while (row < imageHeight-1)
  {
    row++;
    for(column=left; column<right; column++)
    {
      if (isColoredRegion(column, row, inImage, 1, inColor))
      {
        newBottom = row;
        break;
      }
    }
    if (column == right) break;
  }

  return new BoundingRectangle(newTop, newBottom, left, right);
}

