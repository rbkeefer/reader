/*
 * RkSegment.cpp
 *
 */

#include "Separate.h"
#include "RkBoundingRectangle.h"
#include "RkRegions.h"
#include "RkSize.h"
#include "RkSegment.h"

RkSegment::RkSegment()
{
  boundingRectangle = NULL;
  segmentType = 4;
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

void RkSegment::determineType(IplImage* inImage, int inMode)
{
  int key;

  IplImage* segmentImg;
  RkBoundingRectangle* potentialCharFrame;

  cvSetImageROI(inImage, boundingRectangle->toRect());
  segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
  cvCopy(inImage, segmentImg, NULL);

  segmentImg = cleanupImage(segmentImg);
  potentialCharacterFrames = regionizeImage(segmentImg, BLACK);

  list<RkBoundingRectangle*>::iterator potentialCharacterFramesIter;
  for (potentialCharacterFramesIter=potentialCharacterFrames.begin();
	   potentialCharacterFramesIter!=potentialCharacterFrames.end();
	   potentialCharacterFramesIter++)
  {
	potentialCharFrame = (*potentialCharacterFramesIter);
	if ((inMode == MANUAL_MODE) || (isCharacter(potentialCharFrame, segmentImg)))
	{
	  cvNamedWindow("segment", CV_WINDOW_AUTOSIZE);
	  cvShowImage("segment", segmentImg);

	  key = cvWaitKey(0);
	  switch(key)
	  {
	        case 't':
	          segmentType = 2;
	          break;
	        case 'l':
	          segmentType = 3;
	          break;
	        case 'i':
	          segmentType = 4;
	          break;
	  }

	  cvReleaseImage(&segmentImg);
	  cvDestroyWindow("segment");

	  break;
	}
  }

  cvResetImageROI(inImage);
}

bool RkSegment::isCharacter(RkBoundingRectangle* inCharFrame, IplImage* inImage)
{
    int ht = inCharFrame->height();
    int wd = inCharFrame->width();
    if ((ht > 8) && (wd > 6))
    {
      return true;
    }

    return false;
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
