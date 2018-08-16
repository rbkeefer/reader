/*
 * RkUtils.cpp
 *
 */

#include "Separate.h"
#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkTextFrame.h"
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

IplImage* displayBoundaries(IplImage* inImage, list<RkSegment*> inSegmentList, int inSize)
{
  CvScalar noColor = cvScalar(255, 0, 0);
  CvScalar headlineColor = cvScalar(0, 0, 255);
  CvScalar textColor = cvScalar(0, 255, 0);
  CvScalar lineColor = cvScalar(0, 255, 255);
  CvScalar imgColor = cvScalar(255, 0, 255);
  CvScalar drawColor;

  RkBoundingRectangle* charFrame;
  RkSegment* segment;
  int segmentType;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter);
	segmentType = segment->segmentType;

    list<RkBoundingRectangle*>::iterator potentialCharacterFramesIter;

    if (segmentType == 1 || segmentType == 2)
    {
		for (potentialCharacterFramesIter=(segment->potentialCharacterFrames).begin();
			 potentialCharacterFramesIter!=(segment->potentialCharacterFrames).end();
			 potentialCharacterFramesIter++)
		{
		  charFrame = (*potentialCharacterFramesIter);

		  charFrame->top = charFrame->top + segment->boundingRectangle->top;
		  charFrame->left = charFrame->left + segment->boundingRectangle->left;
		  charFrame->bottom = charFrame->bottom + segment->boundingRectangle->top;
		  charFrame->right = charFrame->right + segment->boundingRectangle->left;
		  displayBoundaries(inImage, charFrame, cvScalar(128, 0, 255), inSize);
		}
    }

	switch (segmentType)
	{
		case 1: drawColor = headlineColor; break;
		case 2: drawColor = textColor; break;
		// case 3: drawColor = lineColor; break;
		// case 4: drawColor = imgColor; break;

		default: drawColor = noColor; break;
	}

	displayBoundaries(inImage, segment->boundingRectangle, drawColor, inSize);
  }

  return inImage;
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

