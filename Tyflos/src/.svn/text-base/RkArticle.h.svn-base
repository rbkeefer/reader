/*
 * RkArticle.h
 *
 */

#ifndef RKARTICLE_H_
#define RKARTICLE_H_

class RkArticle {
public:
	RkArticle();
	virtual ~RkArticle();

	RkSegment* headline;
	list<RkSegment*> columns;

	RkBoundingRectangle* boundingRectangle();
	void join(RkArticle* inArticle);

	bool equals(RkArticle* inArticle);

	void toString();
    void printString(FILE* inFile);
};

#endif /* RKARTICLE_H_ */
