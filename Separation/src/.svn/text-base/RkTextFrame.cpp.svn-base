/*
 * RkTextFrame.cpp
 *
 */

#include "RkCharacter.h"
#include "RkTextFrame.h"

RkTextFrame::RkTextFrame() {

}

RkTextFrame::RkTextFrame(RkBoundingRectangle* inBoundingRect, list<RkCharacter*> inCharList) {
	characterList = inCharList;
	boundingRectangle = inBoundingRect;
}

RkTextFrame::~RkTextFrame() {
	// Do Nothing for now
}

int RkTextFrame::getFontSize() {
  int fontSize = 0;
  RkCharacter* character;
  list<RkCharacter*>::iterator characterIter;

  for (characterIter=characterList.begin(); characterIter!=characterList.end(); characterIter++)
  {
    character = (*characterIter);
    if (character->fontSize() > fontSize) fontSize = character->fontSize();
  }

  return fontSize;
}

bool RkTextFrame::equals(RkTextFrame* inFrame) {
  if (boundingRectangle->equals(inFrame->boundingRectangle)) return true;
  return false;
}
