/*
 * RkUtils.cpp
 *
 */

#include "Segment.h"
#include "RkBoundingRectangle.h"
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



IplImage* displayBoundaries(IplImage* inImage, list<RkBoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize)
{
  int width = inImage->width;
  int height = inImage->height;
  RkBoundingRectangle* rectangle;
  list<RkBoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    if (rectangle->bottom >= height) rectangle->bottom = height-1;
    if (rectangle->right >= width) rectangle->right = width-1;
    cvRectangle(inImage, rectangle->topLeft(), rectangle->bottomRight(), inColor, inSize);
  }

  return inImage;
}

RkBoundingRectangle* groupVerticleRectangles(RkBoundingRectangle* inRectangle, list<RkBoundingRectangle*> inRectangleList, int inTolerance)
{
  bool testedAllSegments = false;
  RkBoundingRectangle* rectangle;

  RkBoundingRectangle* baseRectangle = inRectangle;

  if (inRectangleList.size() > 0)
  {
	  int baseArea = baseRectangle->area() - 1;
	  list<RkBoundingRectangle*>::iterator rectangleIter=inRectangleList.begin();

	  while (! ((baseArea == baseRectangle->area()) && (testedAllSegments)))
	  {
		testedAllSegments = false;
		baseArea = baseRectangle->area();
		rectangle = (*rectangleIter);

		if (baseRectangle->isVerticalOverlap(rectangle))
		  baseRectangle->join(rectangle);

		if (baseRectangle->isAbove(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
			baseRectangle->join(rectangle);
		}

		if (baseRectangle->isBelow(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
			baseRectangle->join(rectangle);
		}

		rectangleIter++;

		if (rectangleIter == inRectangleList.end())
		{
		  rectangleIter = inRectangleList.begin();
		  testedAllSegments = true;
		}
	  }
  }
  return baseRectangle;
}

bool isRectangleInRectangleList(RkBoundingRectangle* inRectangle, list<RkBoundingRectangle*> inRectangleList)
{
  RkBoundingRectangle* rectangle;
  list<RkBoundingRectangle*>::iterator rectangleIter;
  for (rectangleIter=inRectangleList.begin(); rectangleIter!=inRectangleList.end(); rectangleIter++)
  {
    rectangle = (*rectangleIter);
    if (rectangle->isRectIn(inRectangle)) return true;
  }

  return false;
}

list<RkBoundingRectangle*> eliminateVerticalOverlap(list<RkBoundingRectangle*> inRectangleList)
{
  RkBoundingRectangle* rectangle;
  RkBoundingRectangle* newRectangle;
  list<RkBoundingRectangle*> rectangleList;
  list<RkBoundingRectangle*> returnList;
  list<RkBoundingRectangle*>::iterator rectangleIter;

  for (rectangleIter=inRectangleList.begin(); rectangleIter!=inRectangleList.end(); rectangleIter++)
  {
	rectangle = (*rectangleIter);
	if (! isRectangleInRectangleList(rectangle, rectangleList))
	{
	  newRectangle = groupVerticleRectangles(rectangle, inRectangleList, -8);
	  rectangleList.push_back(newRectangle);
	}
  }

  rectangleList.reverse();
  for (rectangleIter=rectangleList.begin(); rectangleIter!=rectangleList.end(); rectangleIter++)
  {
	rectangle = (*rectangleIter);
	rectangle->toString();
	if (! isRectangleInRectangleList(rectangle, returnList))
	{
	  newRectangle = groupVerticleRectangles(rectangle, rectangleList, -8);
	  returnList.push_back(newRectangle);
	}
  }

  return returnList;
}


