/*
 * RkUtils.cpp
 *
 */

#include "Reader.h"
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
  if (inRectangle->pointIn(inPoint.x, inPoint.y, inTolerance))
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

IplImage* displayBoundaries(IplImage* inImage, list<RkArticle*> inArticleList,
                            CvScalar inColor, int inSize)
{
  RkBoundingRectangle* rectangle;
  list<RkArticle*>::iterator articleIter;
  list<RkBoundingRectangle*> boundingRectList;

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
    rectangle = (*articleIter)->boundingRectangle();
    rectangle->toString();
    boundingRectList.push_back(rectangle);
  }

  return displayBoundaries(inImage, boundingRectList, inColor, inSize);
}

bool compareTextFrameTopLeft(RkTextFrame* first, RkTextFrame* second) {
  int firstRect = (first->boundingRectangle->left * first->boundingRectangle->left) +
				  (first->boundingRectangle->top * first->boundingRectangle->top);

  int secondRect = (second->boundingRectangle->left * second->boundingRectangle->left) +
				   (second->boundingRectangle->top * second->boundingRectangle->top);

  if (sqrt(firstRect) < sqrt(secondRect))
	return true;

  return false;
}

bool compareTextFrameBottomRight(RkTextFrame* first, RkTextFrame* second) {
  int firstRect = (first->boundingRectangle->right * first->boundingRectangle->right) +
				  (first->boundingRectangle->bottom * first->boundingRectangle->bottom);

  int secondRect = (second->boundingRectangle->right * second->boundingRectangle->right) +
				   (second->boundingRectangle->bottom * second->boundingRectangle->bottom);

  if (sqrt(firstRect) > sqrt(secondRect))
	return true;

  return false;
}

bool sameTextFrame(RkTextFrame* first, RkTextFrame* second)
{
	if (first->boundingRectangle->equals(second->boundingRectangle)) return true;
	return false;
}

