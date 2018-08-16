/*
 * RkClassifySegments.cpp
 *
 */

#include "Classify.h"
#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkClassifySegments.h"

int findBreak(map<int, int> inHeights);

void classifySegments(list<RkSegment*> inSegmentList, IplImage* inImage)
{
  map<int, int> fontHeights;
  int maxHeight;

  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    maxHeight = segment->maxCharHeight(inImage);
    fontHeights[maxHeight] = fontHeights[maxHeight] + 1;
  }

  for(map<int, int>::iterator iter = fontHeights.begin(); iter != fontHeights.end(); iter++)
  {
    printf("Height: %d   Number: %d\n", (*iter).first, (*iter).second);
  }

  int histogramBreak = findBreak(fontHeights);

  printf("BREAK: %d\n", histogramBreak);

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    if (segment->maxCharHeight(inImage) >= histogramBreak)
    	segment->segmentType = 1;
  }

  return;
}

int findBreak(map<int, int> inHeights)
{
  int histBreak = 1;
  int prevKey = 0;

  for(map<int, int>::iterator iter = inHeights.begin(); iter != inHeights.end(); iter++)
  {
	  if ((*iter).first > prevKey + 3)
	  {
		  histBreak = (*iter).first;
	  }

	  prevKey = (*iter).first;
  }

  return histBreak;
}

void manualClassifySegments(list<RkSegment*> inSegmentList, IplImage* inImage)
{
  int key;
  IplImage* segmentImg;
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    cvSetImageROI(inImage, segment->boundingRectangle->toRect());
    segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
    cvCopy(inImage, segmentImg, NULL);
    cvNamedWindow("segment", CV_WINDOW_AUTOSIZE);
    cvShowImage("segment", segmentImg);

    key = cvWaitKey(0);
    switch(key)
    {
	case 'h':
	  segment->segmentType = 1;
	  break;
	case 't':
	  segment->segmentType = 2;
	  break;
	case 'l':
	  segment->segmentType = 3;
	  break;
	case 'i':
	  segment->segmentType = 4;
	  break;
    }

    cvReleaseImage(&segmentImg);
    cvDestroyWindow("segment");
  }

  cvResetImageROI(inImage);

}
