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
	virtual ~RkSegment();

	list<RkBoundingRectangle*> potentialCharacterFrames;
	RkBoundingRectangle* boundingRectangle;
	int segmentType;

	void determineType(IplImage* inImage, int inMode);

	bool isCharacter(RkBoundingRectangle* inCharFrame, IplImage* inImage);

	void printString(FILE* inFile);

};

#endif /* RKSEGMENT_H_ */
