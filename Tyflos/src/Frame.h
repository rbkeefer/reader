/*
 * Frame.h
 *
 */

#ifndef FRAME_H_
#define FRAME_H_

void doFraming(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage);

list<RkArticle*> groupArticles(list<RkSegment*> inSegmentList);
RkArticle* groupArticles(RkArticle* inArticle, list<RkArticle*> inArticleList);

list<RkSegment*> groupHeadlines(list<RkSegment*> inSegmentList);
list<RkSegment*> groupTextColumns(list<RkSegment*> inSegmentList);

RkBoundingRectangle* groupHorizontalSegments(RkSegment* inSegment, list<RkSegment*> inSegmentList, int inTolerance);
RkBoundingRectangle* groupVerticleSegments(RkSegment* inSegment, list<RkSegment*> inSegmentList, int inTolerance);

bool isColumnWithHeadline(RkSegment* inColumn, RkSegment* inHeadline, list<RkSegment*> inHeadlineList);

list<RkSegment*> getClassifiedSegmentList(string* inFileName);
void dumpFramedSegmentList(list<RkArticle*> inArticleList, string* inFileName);

#endif /* FRAME_H_ */
