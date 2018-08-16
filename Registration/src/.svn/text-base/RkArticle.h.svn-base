/*
 * RkArticle.h
 *
 */

#ifndef RKARTICLE_H_
#define RKARTICLE_H_

#include <list>
#include "RkSegment.h"

class RkArticle {
public:
	RkArticle();
	virtual ~RkArticle();

	RkSegment* headline;
	list<RkSegment*> columns;

	RkBoundingRectangle* boundingRectangle();
	int height();
	int width();
	int numberOfColumns();
	int distBetweenColumns();

	void info();
	void toString();
    void printString(FILE* inFile);
};

#endif /* RKARTICLE_H_ */
