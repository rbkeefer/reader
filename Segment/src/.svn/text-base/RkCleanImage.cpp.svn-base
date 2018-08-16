/*
 * RkCleanImage.cpp
 *
 */

#include "Segment.h"
#include "RkBoundingRectangle.h"
#include "RkColumn.h"
#include "RkRegions.h"
#include "RkUtils.h"
#include "RkSize.h"

bool isColoredRow(int inColumn, int inRow, IplImage* inImage, int inColor);
bool isColoredColumn(int inColumn, int inRow, IplImage* inImage, int inColor);

list<RkBoundingRectangle*> findSmallRegions(IplImage* inImage, int inColor);
IplImage* removeSmallRegions(IplImage* inImage, list<RkBoundingRectangle*> inRegionList, int inColor);

IplImage* cleanImage(IplImage* inImage, int inThreshold)
{
  IplImage* outImage = cvCloneImage(inImage);
//  cvThreshold(inImage, outImage, inThreshold, 255, CV_THRESH_BINARY);

  long pixelValue = 0;
  int avgPixels = 0;

  int column, row, pixel;
  uchar* tmpImageData = (uchar*) outImage->imageData;
  int imgStep = outImage->widthStep;
  int imgWidth = outImage->width;
  int imgHeight = outImage->height;

  for(column=0; column<imgWidth; column++)
  {
    for( row=0; row<imgHeight; row++ )
    {
      pixel = column + (row * imgStep);
      pixelValue += tmpImageData[pixel];
    }
  }

  avgPixels = pixelValue/(imgWidth*imgHeight);

  printf("\nAVERAGE PIXEL VALUE: %d\n", avgPixels);

  for(column=0; column<imgWidth; column++)
  {
    for( row=0; row<imgHeight; row++ )
    {
      pixel = column + (row * imgStep);

      if (tmpImageData[pixel] > avgPixels - 15)
      {
    	  tmpImageData[pixel] = WHITE;
      }
      else
      {
    	  tmpImageData[pixel] = BLACK;
      }

//      if ( tmpImageData[pixel] == BLACK )
//      {
//        if (! isColoredRegion(column, row, outImage, 1, BLACK))
//    	{
//          tmpImageData[pixel] = WHITE;
//        }
//      }
    }
  }

//  for(column=2; column<imgWidth-2; column++)
//  {
//    for( row=2; row<imgHeight-2; row++ )
//    {
//      pixel = column + (row * imgStep);
//
//      if ( tmpImageData[pixel] == BLACK )
//      {
//        if (isColoredRow(column, row, outImage, BLACK))
//    	{
//          tmpImageData[pixel-1] = WHITE;
//          tmpImageData[pixel] = WHITE;
//        }
//      }
//    }
//  }

  return outImage;
}

bool isColoredRow(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int inImageStep = inImage->widthStep;

  int thisPixel = (inColumn) + (inRow * inImageStep);
  int pixelBack1 = thisPixel - 1;
  int pixelForward1 = thisPixel + 1;
  int pixelBack2 = thisPixel - 2;
  int pixelForward2 = thisPixel + 2;

    if ( (inImageData[pixelBack1] == WHITE) || (inImageData[pixelBack2] == WHITE) )
    {
    	if ((inImageData[pixelForward1] == WHITE) && (inImageData[pixelForward2] == WHITE))
    	{
    		return true;
    	}
    }

//    if ( (inImageData[pixelBack1] == WHITE) && (inImageData[pixelBack2] == WHITE) )
//    {
//    	if ((inImageData[pixelForward1] == WHITE) || (inImageData[pixelForward2] == WHITE))
//    	{
//    		return true;
//    	}
//    }

  return false;
}

//  list<RkBoundingRectangle*> regionList = findSmallRegions(outImage, BLACK);
//  outImage = removeSmallRegions(outImage, regionList, WHITE);

list<RkBoundingRectangle*> findSmallRegions(IplImage* inImage, int inColor)
{
  CvPoint point;
  list<RkBoundingRectangle*> boundingRectList;
  RkBoundingRectangle* boundingRect;

  list<RkColumn*> columns = findColumns(inImage, 5, inColor);


  list<RkColumn*>::iterator columnIter;
  for (columnIter=columns.begin(); columnIter!=columns.end(); columnIter++)
  {
	  printf("COLUMN: %d  [%d, %d]  %d]\n", (*columnIter)->column, (*columnIter)->top, (*columnIter)->bottom, (*columnIter)->height());

	  point.x = (*columnIter)->column; point.y = (*columnIter)->top;
      if (! isBoundByRectangle(point, boundingRectList, 0))
      {
    	  boundingRect = regionBoundary((*columnIter)->column, (*columnIter)->top, inImage, inColor);
    	  printf("REGION: [%d, %d, %d, %d]  %d\n\n", boundingRect->top, boundingRect->left, boundingRect->bottom, boundingRect->right, boundingRect->height());
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
      }



//      if (NULL != boundingRect)
//      {
//    	if (boundingRect->width() < 5)
//    	{
//    		printf("Adding region: [%d, %d, %d, %d]\n", boundingRect->top, boundingRect->left, boundingRect->bottom, boundingRect->right);
//          boundingRectList.push_back(boundingRect);
//    	}
//      }
  }

  return boundingRectList;
}

IplImage* removeSmallRegions(IplImage* inImage, list<RkBoundingRectangle*> inRegionList, int inColor)
{
  uchar* tmpImageData = (uchar *) inImage->imageData;
  int imageStep = inImage->widthStep;
  RkBoundingRectangle* boundingRect;

  printf("RemoveSmallRegions ...\n");

  list<RkBoundingRectangle*>::iterator regionIter;
  for (regionIter=inRegionList.begin(); regionIter!=inRegionList.end(); regionIter++)
  {
	  boundingRect = (*regionIter);
		printf("clearing region: [%d, %d, %d, %d]\n", boundingRect->top, boundingRect->left, boundingRect->bottom, boundingRect->right);
	  for (int row=boundingRect->top; row < boundingRect->bottom; row++)
	  {
        for (int column=boundingRect->left; column < boundingRect->right; column++)
	    {
		  tmpImageData[(row*imageStep) + column] = inColor;
	    }
	  }
  }

  return inImage;
}

