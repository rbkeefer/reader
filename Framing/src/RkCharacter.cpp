/*
 * RkCharacter.cpp
 *
 */

#include "RkCharacter.h"

RkCharacter::RkCharacter() {
	boundingRectangle = new RkBoundingRectangle();
}

RkCharacter::RkCharacter(RkBoundingRectangle* inBoundingRect) {
	boundingRectangle = inBoundingRect;
}

RkCharacter::~RkCharacter() {
	// Do Nothing for now
}

int RkCharacter::fontSize() {
	return boundingRectangle->height();
}

bool RkCharacter::equals(RkCharacter* inChar) {

	return(boundingRectangle->equals(inChar->boundingRectangle));

}
