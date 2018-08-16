/*
 * Separate.h
 *
 */

#ifndef SEPARATE_H_
#define SEPARATE_H_

void doSeparation(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage);

void dumpSeparatedSegmentList(list<RkSegment*> inSegmentList, string* inFileName);

list<RkSegment*> getSegmentList(string* inFileName);

const int MIN_SEPARATION_HEIGHT = 5;
const int MIN_SEGPARATION_WIDTH = 5;


#endif /* SEPARATE_H_ */
