/*
 * RkSegment.cpp
 *
 */

#include "Classify.h"
#include "RkBoundingRectangle.h"
#include "RkRegions.h"
#include "RkSize.h"
#include "RkSegment.h"

RkSegment::RkSegment()
{
  boundingRectangle = NULL;
  segmentType = 0;
}

RkSegment::RkSegment(int inTop, int inLeft, int inBottom, int inRight, int inSegmentType)
{
  boundingRectangle  = new RkBoundingRectangle(inTop, inLeft, inBottom, inRight);
  segmentType = inSegmentType;
}

RkSegment::RkSegment(RkBoundingRectangle* inBoundingRect, int inSegmentType)
{
  boundingRectangle = inBoundingRect;
  segmentType = inSegmentType;
}

RkSegment::~RkSegment()
{
	// Do Nothing for now
}

void RkSegment::printString(FILE* inFile)
{
  fprintf(inFile, "%d,%d,%d,%d,%d\n",
		  boundingRectangle->top,
		  boundingRectangle->left,
		  boundingRectangle->bottom,
		  boundingRectangle->right,
		  segmentType);
}

int RkSegment::maxCharHeight(IplImage* inImage)
{
  if (segmentType != 2) return 0;

  IplImage* segmentImg;
  RkBoundingRectangle* charFrame;

  cvSetImageROI(inImage, boundingRectangle->toRect());
  segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
  cvCopy(inImage, segmentImg, NULL);

  segmentImg = cleanupImage(segmentImg);
  characterFrames = regionizeImage(segmentImg, BLACK);

  int maxHeight = 0;
  list<RkBoundingRectangle*>::iterator characterFramesIter;
  for (characterFramesIter=characterFrames.begin();
	   characterFramesIter!=characterFrames.end();
	   characterFramesIter++)
  {
	charFrame = (*characterFramesIter);
	if (maxHeight < charFrame->height())
	  maxHeight = charFrame->height();
  }

  cvResetImageROI(inImage);

  return maxHeight;
}
