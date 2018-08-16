/*
 * RkSegment.cpp
 *
 */

#include "Reader.h"
#include "RkBoundingRectangle.h"
#include "RkSegment.h"

#include "Regions.h"
#include "CleanImage.h"

RkSegment::RkSegment()
{
  boundingRectangle = NULL;
  segmentType = IMAGE_TYPE;
  maxCharHeight = 0;
  avgCharHeight = 0;
}

RkSegment::RkSegment(RkBoundingRectangle* inBoundingRect, int inSegmentType)
{
  boundingRectangle = inBoundingRect;
  segmentType = inSegmentType;
  maxCharHeight = 0;
  avgCharHeight = 0;
}

RkSegment::~RkSegment()
{
  if (NULL != boundingRectangle)
	free(boundingRectangle);

  if (characterFrames.size() > 0)
  {
    list<RkBoundingRectangle*>::iterator characterFramesIter;
    for (characterFramesIter=characterFrames.begin();
         characterFramesIter!=characterFrames.end();
         characterFramesIter++)
      free(*characterFramesIter);
  }
}

void RkSegment::determineType(IplImage* inImage, int inMode)
{
  bool promptForType = false;
  int key;

  IplImage* segmentImg;
  RkBoundingRectangle* charFrame;

  cvSetImageROI(inImage, boundingRectangle->toRect());
  segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
  cvCopy(inImage, segmentImg, NULL);

  if (inMode == MANUAL_MODE)
	promptForType = true;
  else
  {
	  list<RkBoundingRectangle*>::iterator characterFramesIter;
	  characterFrames = getRegionBoundaries(segmentImg, BLACK);
	  for (characterFramesIter=characterFrames.begin();
		   characterFramesIter!=characterFrames.end();
		   characterFramesIter++)
	  {
		charFrame = (*characterFramesIter);
	    if (isCharacter(charFrame, segmentImg))
	    {
	    	promptForType = true; break;
	    }
	  }
  }

  if (promptForType)
  {
    cvNamedWindow("segment", CV_WINDOW_AUTOSIZE);
    cvShowImage("segment", segmentImg);

    key = cvWaitKey(0);
    switch(key)
    {
		case 't':
		  segmentType = CONTENT_TYPE;
		  break;
		case 'l':
		  segmentType = LINE_TYPE;
		  break;
		case 'i':
		  segmentType = IMAGE_TYPE;
		  break;
    }

    cvReleaseImage(&segmentImg);
    cvDestroyWindow("segment");
  }

  cvResetImageROI(inImage);
}

int RkSegment::getAvgHeight(IplImage* inImage)
{
  if (segmentType != CONTENT_TYPE) return 0;

  if (avgCharHeight > 0) return avgCharHeight;

  calculateHeights(inImage);

  return avgCharHeight;
}

int RkSegment::getMaxHeight(IplImage* inImage)
{
  if (segmentType != CONTENT_TYPE) return 0;

  if (maxCharHeight > 0) return maxCharHeight;

  calculateHeights(inImage);

  return maxCharHeight;
}

void RkSegment::calculateHeights(IplImage* inImage)
{
  int totalHeight=0;

  IplImage* segmentImg;
  RkBoundingRectangle* charFrame;

  cvSetImageROI(inImage, boundingRectangle->toRect());
  segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
  cvCopy(inImage, segmentImg, NULL);

  characterFrames = getRegionBoundaries(segmentImg, BLACK);

  list<RkBoundingRectangle*>::iterator characterFramesIter;
  for (characterFramesIter=characterFrames.begin();
	   characterFramesIter!=characterFrames.end();
	   characterFramesIter++)
  {
    charFrame = (*characterFramesIter);

	if (maxCharHeight < charFrame->height())
	  maxCharHeight = charFrame->height();

	totalHeight += charFrame->height();
  }

  avgCharHeight = totalHeight / characterFrames.size();

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

CvScalar RkSegment::getDrawColor()
{
  CvScalar drawColor = COLOR_BLUE;

  switch (segmentType)
  {
	case HEADLINE_TYPE: drawColor = COLOR_GREEN; break;
	case CONTENT_TYPE: drawColor = COLOR_RED; break;
	case LINE_TYPE: drawColor = COLOR_YELLOW; break;
	case IMAGE_TYPE: drawColor = COLOR_PURPLE; break;

	default: drawColor = COLOR_BLUE; break;
  }

  return drawColor;
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
