/*
 * Utils.cpp
 *
 */

#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"
#include "Utils.h"

bool isColoredRegion(int inColumn, int inRow, int inRegionSize, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imgStep = inImage->widthStep;
  int imgWidth = inImage->width;
  int imgHeight = inImage->height;
  int startColumn = (inColumn < inRegionSize) ? 0 : inColumn - inRegionSize;
  int startRow = (inRow < inRegionSize) ? 0 : inRow - inRegionSize;
  int lastColumn = (inColumn < imgWidth - inRegionSize) ? inColumn + inRegionSize : imgWidth;
  int lastRow = (inRow < imgHeight - inRegionSize) ? inRow + inRegionSize : imgHeight;
  int pixel;
  int column, row;

  for(column=startColumn; column<lastColumn; column++)
  {
  for(row=startRow; row<lastRow; row++)
  {
      if ((row == inRow) && (column == inColumn)) break;
      pixel = (row * imgStep) + column;

      if ( inImageData[pixel] == inColor )
    	  return true;
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

bool isPointBoundByRectangle(CvPoint inPoint, list<RkBoundingRectangle*> inRectangleList, int inTolerance)
{
  RkBoundingRectangle* boundingRect;
  list<RkBoundingRectangle*>::iterator iter;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    boundingRect = (*iter);
    if (isPointBoundByRectangle(inPoint, boundingRect, inTolerance))
      return true;
  }

  return false;
}

bool isPointBoundByRectangle(CvPoint inPoint, RkBoundingRectangle* inRectangle, int inTolerance)
{
  if (inRectangle->isPointIn(inPoint.x, inPoint.y, inTolerance))
    return true;

  return false;
}

bool isSimilarHeight(RkBoundingRectangle* inRect1, RkBoundingRectangle* inRect2, int inTolerance)
{
  if ((inRect1->height()+inTolerance >= inRect2->height()) &&
      (inRect2->height()+inTolerance >= inRect1->height()))
	  return true;

  return false;
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

bool isSegmentInSegmentList(RkSegment* inSegment, list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    if (segment->boundingRectangle->isRectIn(inSegment->boundingRectangle)) return true;
  }

  return false;
}

bool isArticleInArticleList(RkArticle* inArticle, list<RkArticle*> inArticleList)
{
  RkArticle* article;
  list<RkArticle*>::iterator articleIter;
  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
    article = (*articleIter);
    if ((article->boundingRectangle())->isRectIn(inArticle->boundingRectangle())) return true;
  }

  return false;
}

RkSegment* getLargestSegment(list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  RkSegment* largestSegment = NULL;
  list<RkSegment*>::iterator segmentIter;
  int largestArea = 0;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter); if (NULL == largestSegment) largestSegment = segment;
	if (largestArea < segment->boundingRectangle->area())
	{
		largestSegment = segment;
		largestArea = largestSegment->boundingRectangle->area();
	}
  }

  return largestSegment;
}

list<RkSegment*> getTypedSegments(list<RkSegment*> inSegmentList, int inType)
{
  list<RkSegment*> segmentList;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	if ((*segmentIter)->segmentType == inType)
	  segmentList.push_back((*segmentIter));
  }

  return segmentList;
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

IplImage* displayBoundaries(IplImage* inImage, RkBoundingRectangle* inRectangle,
                            CvScalar inColor, int inSize)
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
  list<RkBoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
	 displayBoundaries(inImage, (*iter), inColor, inSize);
  }

  return inImage;
}

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList, int inSize)
{
  RkBoundingRectangle* charFrame;
  RkSegment* segment;
  int segmentType;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter);
	segmentType = segment->segmentType;

	list<RkBoundingRectangle*>::iterator characterFramesIter;
	if (segmentType == 1 || segmentType == 2)
	{
		for (characterFramesIter=(segment->characterFrames).begin();
				 characterFramesIter!=(segment->characterFrames).end();
				 characterFramesIter++)
		{
		  charFrame = (*characterFramesIter);

		  charFrame->top = charFrame->top + segment->boundingRectangle->top;
		  charFrame->left = charFrame->left + segment->boundingRectangle->left;
		  charFrame->bottom = charFrame->bottom + segment->boundingRectangle->top;
		  charFrame->right = charFrame->right + segment->boundingRectangle->left;
		  displayBoundaries(inImage, charFrame, COLOR_RED, inSize/2);
		}
	}


	displayBoundaries(inImage, segment->boundingRectangle, segment->getDrawColor(), inSize);
  }

  return inImage;
}

IplImage* displayBoundaries(IplImage* inImage, list<RkArticle*> inArticleList, int inSize)
{
  RkArticle* article;
  RkBoundingRectangle* rectangle;
  list<RkArticle*>::iterator articleIter;
  list<RkBoundingRectangle*> boundingRectList;

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
	article = (*articleIter);

	rectangle = (*articleIter)->boundingRectangle();
    inImage = displayBoundaries(inImage, rectangle, COLOR_BLUE, inSize);

    if ((NULL != article->headline) && (NULL != article->headline->boundingRectangle))
    {
      rectangle = article->headline->boundingRectangle;
      inImage = displayBoundaries(inImage, rectangle, COLOR_GREEN, inSize/2);
    }

    inImage = displayBoundaries(inImage, article->columns, inSize/2);

    (*articleIter)->toString();
  }

  return inImage;
}
