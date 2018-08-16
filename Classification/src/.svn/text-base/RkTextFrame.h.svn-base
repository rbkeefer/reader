/*
 * RkTextFrame.h
 *
 */

#ifndef RKTEXTFRAME_H_
#define RKTEXTFRAME_H_

#include <list>

#include "RkBoundingRectangle.h"
#include "RkCharacter.h"

using namespace std;

class RkTextFrame {
public:
	RkTextFrame();
	RkTextFrame(RkBoundingRectangle* inBoundingRect, list<RkCharacter*> inCharList);
	virtual ~RkTextFrame();

	list<RkCharacter*> characterList;
	RkBoundingRectangle* boundingRectangle;

	int frameType;

	int getFontSize();
	bool equals(RkTextFrame*);
	bool isNear(RkTextFrame*, int);
	bool isBelow(RkTextFrame*, int);
};

#endif /* RKTEXTFRAME_H_ */
