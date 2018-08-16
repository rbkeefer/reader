/*
 * RkArticle.h
 *
 */

#ifndef RKARTICLE_H_
#define RKARTICLE_H_

#include <list>
#include "RkTextFrame.h"
#include "RkSegment.h"

class RkArticle {
public:
	RkArticle();
	virtual ~RkArticle();

	RkSegment* headline;
	list<RkSegment*> columns;

	RkBoundingRectangle* boundingRectangle();

	void toString();
    void printString(FILE* inFile);
};

#endif /* RKARTICLE_H_ */
