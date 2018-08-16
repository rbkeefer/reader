/*
 * RkFrames.h
 *
 */

#ifndef RKFRAMES_H_
#define RKFRAMES_H_

list<RkArticle*> getArticleList(list<RkBoundingRectangle*> regionList, IplImage* cleanedImg);
list<RkArticle*> groupArticles(list<RkSegment*> inSegmentList);


#endif /* RKFRAMES_H_ */
