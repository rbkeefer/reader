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

bool RkTextFrame::isNear(RkTextFrame* inFrame, int inTolerance) {
  if (frameType != inFrame->frameType) return false;
  if (! boundingRectangle->isNear(inFrame->boundingRectangle, inTolerance)) return false;

//  int thisHeight = boundingRectangle->height();
//  int compHeight = inFrame->boundingRectangle->height();
//  if ((compHeight < thisHeight-(inTolerance*2)) || (compHeight > thisHeight+(inTolerance*2))) return false;
//
//  int thisFontSize = getFontSize();
//  int compFontSize = inFrame->getFontSize();
//  if ((compFontSize < thisFontSize-(inTolerance/4)) || (compFontSize > thisFontSize+(inTolerance/4))) return false;

  return true;
}

bool RkTextFrame::isBelow(RkTextFrame* inFrame, int inTolerance) {
  int thisTop = boundingRectangle->top;   int thisBottom = boundingRectangle->bottom;
  int compTop = inFrame->boundingRectangle->top;   int compBottom = inFrame->boundingRectangle->bottom;
  if ((compBottom < thisTop-inTolerance) || (compBottom > thisBottom+inTolerance)) return false;

  int thisLeft = boundingRectangle->left;   int thisRight = boundingRectangle->right;
  int compLeft = inFrame->boundingRectangle->left;   int compRight = inFrame->boundingRectangle->right;
  if ((compRight < thisLeft) || (compRight > thisRight)) return false;

  return true;
}
