/*
 * Segment.h
 *
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

void doSegmentation(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage);

list<RkBoundingRectangle*> groupRegions(list<RkBoundingRectangle*> inRegionList);
RkBoundingRectangle* groupRegions(RkBoundingRectangle* inRegion, list<RkBoundingRectangle*> inRegionList);

void dumpSegmentList(list<RkBoundingRectangle*> inRectangleList, const char* inFileName);

const int MIN_SEGMENTATION_HEIGHT = 15;
const int MIN_SEGMENTATION_WIDTH = 25;

#endif /* SEGMENT_H_ */
