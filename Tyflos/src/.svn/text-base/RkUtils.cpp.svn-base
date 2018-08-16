/*
 * RkUtils.cpp
 *
 */

#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkUtils.h"

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
  CvScalar drawColor = COLOR_BLUE;

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
		  displayBoundaries(inImage, charFrame, COLOR_RED, inSize/2);
		}
	}

	switch (segmentType)
	{
		case 1: drawColor = COLOR_GREEN; break;
		case 2: drawColor = COLOR_RED; break;
		case 3: drawColor = COLOR_YELLOW; break;
		case 4: drawColor = COLOR_PURPLE; break;

		default: drawColor = COLOR_BLUE; break;
	}

	displayBoundaries(inImage, segment->boundingRectangle, drawColor, inSize);
  }

  return inImage;
}
