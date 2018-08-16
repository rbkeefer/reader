/*
 * RkUtils.cpp
 *
 */

#include "Registration.h"
#include "RkBoundingRectangle.h"
#include "RkArticle.h"
#include "RkUtils.h"

bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int inImageStep = inImage->widthStep;
  int columnCounter = 0;
  int rowCounter = 0;
  int pixel;

  if (inRegionSize == 0)
  {
    pixel = inColumn + (inRow * inImageStep);
    if ( inImageData[pixel] == inColor )
      return true;

    return false;
  }

  for( rowCounter=0; rowCounter<inRegionSize; rowCounter++ )
  {
    for( columnCounter=0; columnCounter<inRegionSize; columnCounter++ )
    {
	  pixel = (columnCounter + inColumn) + ((rowCounter+inRow) * inImageStep);

	  if ( inImageData[pixel] == inColor )
	  {
		return true;
	  }
    }
  }

  return false;
}

bool isSamePoint(CvPoint point1, CvPoint point2)
{
  if (point1.x != point2.x) return false;
  if (point1.y != point2.y) return false;
  return true;
}

bool isBoundByRectangle(CvPoint inPoint, list<RkBoundingRectangle*> inRectangleList, int inTolerance)
{
  RkBoundingRectangle* boundingRect;
  list<RkBoundingRectangle*>::iterator iter;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    boundingRect = (*iter);
    if (isBoundByRectangle(inPoint, boundingRect, inTolerance))
      return true;
  }

  return false;
}

bool isBoundByRectangle(CvPoint inPoint, RkBoundingRectangle* inRectangle, int inTolerance)
{
  if (inRectangle->isPointIn(inPoint.x, inPoint.y, inTolerance))
    return true;

  return false;
}


void expandBoundingRectList(list<RkBoundingRectangle*> inRectangleList, int inTimesReduced)
{
  RkBoundingRectangle* rectangle;
  list<RkBoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    rectangle->top = rectangle->top * BOX_SIZE * inTimesReduced;
    rectangle->bottom = (rectangle->bottom * BOX_SIZE * inTimesReduced) + inTimesReduced + BOX_SIZE;
    rectangle->left = rectangle->left * BOX_SIZE* inTimesReduced;
    rectangle->right = (rectangle->right * BOX_SIZE * inTimesReduced) + inTimesReduced + BOX_SIZE;
  }
}

