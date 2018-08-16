/*
 * Classify.h
 *
 */

#ifndef CLASSIFY_H_
#define CLASSIFY_H_

void doClassification(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage);

list<RkSegment*> getSeparatedSegmentList(string* inFileName);
void dumpClassifiedSegmentList(list<RkSegment*> inSegmentList, string* inFileName);

void classifySegments(list<RkSegment*> inSegmentList, IplImage* inImage);
void manualClassifySegments(list<RkSegment*> inSegmentList, IplImage* inImage);
int findBreak(map<int, int> inHeights);



#endif /* CLASSIFY_H_ */
