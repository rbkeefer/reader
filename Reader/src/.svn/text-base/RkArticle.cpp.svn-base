/*
 * RkArticle.cpp
 *
 */

#include "RkArticle.h"

RkArticle::RkArticle() {

}

RkArticle::~RkArticle() {
	// Do Nothing for now
}

RkBoundingRectangle* RkArticle::boundingRectangle() {
  RkBoundingRectangle* returnRect = new RkBoundingRectangle(2052, 2052, 0, 0);
  RkBoundingRectangle* frameRect;

  RkTextFrame* textFrame;
  list<RkTextFrame*>::iterator textFrameIter;

  // Check headline
  int size = headlineList.size();
  for (textFrameIter=headlineList.begin(); textFrameIter!=headlineList.end(); textFrameIter++)
  {
  	textFrame = (*textFrameIter);
  	frameRect = textFrame->boundingRectangle;

  	returnRect->top = (returnRect->top < frameRect->top) ? returnRect->top : frameRect->top;
  	returnRect->left = (returnRect->left < frameRect->left) ? returnRect->left : frameRect->left;
  	returnRect->bottom = (returnRect->bottom > frameRect->bottom) ? returnRect->bottom : frameRect->bottom;
  	returnRect->right = (returnRect->right > frameRect->right) ? returnRect->right : frameRect->right;
  }

  // Check content
  size = contentList.size();
  for (textFrameIter=contentList.begin(); textFrameIter!=contentList.end(); textFrameIter++)
  {
  	textFrame = (*textFrameIter);
  	frameRect = textFrame->boundingRectangle;

  	returnRect->top = (returnRect->top < frameRect->top) ? returnRect->top : frameRect->top;
  	returnRect->left = (returnRect->left < frameRect->left) ? returnRect->left : frameRect->left;
  	returnRect->bottom = (returnRect->bottom > frameRect->bottom) ? returnRect->bottom : frameRect->bottom;
  	returnRect->right = (returnRect->right > frameRect->right) ? returnRect->right : frameRect->right;
  }

  return returnRect;
}

