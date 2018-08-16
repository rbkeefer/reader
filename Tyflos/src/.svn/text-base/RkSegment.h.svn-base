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

	list<RkBoundingRectangle*> characterFrames;
	RkBoundingRectangle* boundingRectangle;
	int segmentType;
	int maxCharHeight;
	int avgCharHeight;

	void determineType(IplImage* inImage, int inMode);
	bool isCharacter(RkBoundingRectangle* inCharFrame, IplImage* inImage);

	int getAvgHeight(IplImage* inImage);
	int getMaxHeight(IplImage* inImage);

	CvScalar getDrawColor();
	void printString(FILE* inFile);

private:
	void calculateHeights(IplImage* inImage);
};

#endif /* RKSEGMENT_H_ */
