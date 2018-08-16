/*
 * RkSegment.h
 *
 */

#ifndef RKSEGMENT_H_
#define RKSEGMENT_H_

class RkSegment {
public:
	RkSegment();
	RkSegment(RkBoundingRectangle* inBoundingRect, int inSegmentType);
	RkSegment(int inTop, int inLeft, int inBottom, int inRight, int inSegmentType);
	virtual ~RkSegment();

	list<RkBoundingRectangle*> characterFrames;
	RkBoundingRectangle* boundingRectangle;
	int segmentType;

	int maxCharHeight(IplImage* inImage);
	void printString(FILE* inFile);

};

#endif /* RKSEGMENT_H_ */
