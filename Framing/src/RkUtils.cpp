/*
 * RkUtils.cpp
 *
 */

#include "Frame.h"
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

IplImage* displayBoundary(IplImage* inImage, RkBoundingRectangle* inRectangle, CvScalar inColor, int inSize)
{
  int width = inImage->width;
  int height = inImage->height;

  if (inRectangle->bottom >= height) inRectangle->bottom = height-1;
  if (inRectangle->right >= width) inRectangle->right = width-1;
  cvRectangle(inImage, inRectangle->topLeft(), inRectangle->bottomRight(), inColor, inSize);

  return inImage;
}

IplImage* displayBoundaries(IplImage* inImage, list<RkBoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize)
{
  RkBoundingRectangle* rectangle;
  list<RkBoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    inImage = displayBoundary(inImage, rectangle, inColor, inSize);
  }

  return inImage;
}

IplImage* displayBoundaries(IplImage* inImage, list<RkArticle*> inArticleList,
                            CvScalar inColor, int inSize)
{
  RkArticle* article;
  RkBoundingRectangle* rectangle;
  list<RkArticle*>::iterator articleIter;
  list<RkBoundingRectangle*> boundingRectList;

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
	article = (*articleIter);
    rectangle = article->headline->boundingRectangle;
    inImage = displayBoundary(inImage, rectangle, cvScalar(0, 255, 0), 1);

    list<RkSegment*>::iterator columnIter;
    for (columnIter=(article->columns).begin(); columnIter!=(article->columns).end(); columnIter++)
    {
      inImage = displayBoundary(inImage, (*columnIter)->boundingRectangle, cvScalar(255, 0, 0), inSize/2);
    }

    rectangle = (*articleIter)->boundingRectangle();
    inImage = displayBoundary(inImage, rectangle, cvScalar(0, 0, 255), inSize);

    (*articleIter)->toString();
  }

  return inImage;
}

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList,
                            CvScalar inColor, int inSize)
{
  RkBoundingRectangle* rectangle;
  list<RkSegment*>::iterator segmentIter;
  list<RkBoundingRectangle*> boundingRectList;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    rectangle = (*segmentIter)->boundingRectangle;
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

