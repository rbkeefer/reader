/*
 * RkArticle.h
 *
 */

#ifndef RKARTICLE_H_
#define RKARTICLE_H_

#include <list>
#include "RkTextFrame.h"

class RkArticle {
public:
	RkArticle();
	virtual ~RkArticle();

	list<RkTextFrame*> headlineList;
	list<RkTextFrame*> contentList;

	RkBoundingRectangle* boundingRectangle();
};

#endif /* RKARTICLE_H_ */
