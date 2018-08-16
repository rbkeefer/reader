#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "cleanImage.h"
#include "findParts.h"
#include "reduceImage.h"
#include "regionImage.h"
#include "ColumnLine.h"

// Local functions
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
void cleanup();

void expandBoundingRectList(list<BoundingRectangle*> inRectangleList);
IplImage* displayBoundaries(IplImage* inImage,
                            list<BoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize);


// Constants
static char* DEFAULT_IMAGE_NAME = "/Users/rob/Research/Images/test/SimpleTest.bmp";
static int REDUCTION_WIDTH = 128;

// Local variables
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* cleanedReducedImg;
IplImage* columnsImg;
IplImage* expandedImg;
IplImage* regionImg;

int threshold = 128;
int timesReduced = 0;

int main(int argc, char** argv)
{
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);
  reducedImg =  cvCloneImage(cleanedImg);

  /*** Reduce ***/
  while (reducedImg->width > REDUCTION_WIDTH)
  {
    reducedImg = reduceImage(reducedImg);
    timesReduced++;
  }

  expandedImg =  cvCloneImage(reducedImg);
  for (int count = 0; count<timesReduced; count++)
  {
    expandedImg = expandImage(expandedImg);
  }

  cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
  cvShowImage("Original", origImg);
  cvMoveWindow("Original", 15,1);

  cvNamedWindow("Reduced", CV_WINDOW_AUTOSIZE);
  cvShowImage("Reduced", reducedImg);

  // cvNamedWindow("Expanded", CV_WINDOW_AUTOSIZE);
  // cvShowImage("Expanded", expandedImg);
  // cvMoveWindow("Expanded", 550,1);

  list<ColumnLine*> columnLineList = findColumns(reducedImg, WHITE);
  list<RowLine*> rowLineList = findRows(reducedImg, WHITE);

  list<ColumnLine*> expandedColumnLineList = accelerateColumns(reducedImg, columnLineList, rowLineList, WHITE);
  list<RowLine*> expandedRowLineList = accelerateRows(reducedImg, columnLineList, rowLineList, WHITE);

  cleanedReducedImg = cleanReducedImage(reducedImg, expandedColumnLineList, expandedRowLineList, WHITE);


    

  /*** Expand ***/
  expandedImg =  cvCloneImage(cleanedReducedImg);
  for (int count = 0; count<timesReduced; count++)
  {
    expandedImg = expandImage(expandedImg);
  }

  CvPoint topPoint, bottomPoint, leftPoint, rightPoint;
  list<ColumnLine*>::iterator columnIter;
  list<RowLine*>::iterator rowIter;

  columnsImg = cvCreateImage(cvSize(expandedImg->width, expandedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(expandedImg, expandedImg, expandedImg, NULL, columnsImg);

  for (columnIter=expandedColumnLineList.begin(); columnIter!=expandedColumnLineList.end(); columnIter++)
  {
     if ((*columnIter)->height() > MIN_HEIGHT)
     {
       topPoint.x = (*columnIter)->column*BOX_SIZE*timesReduced;
       topPoint.y = (*columnIter)->top*BOX_SIZE*timesReduced;
       bottomPoint.x = (*columnIter)->column*BOX_SIZE*timesReduced;
       bottomPoint.y = (*columnIter)->bottom*BOX_SIZE*timesReduced;
       cvLine(columnsImg, topPoint, bottomPoint, cvScalar(0, 0, 255), 2);
     }
  }

  for (rowIter=expandedRowLineList.begin(); rowIter!=expandedRowLineList.end(); rowIter++)
  {
     if ((*rowIter)->width() > MIN_WIDTH)
     {
       leftPoint.x = (*rowIter)->left*BOX_SIZE*timesReduced;
       leftPoint.y = (*rowIter)->row*BOX_SIZE*timesReduced;
       rightPoint.x = (*rowIter)->right*BOX_SIZE*timesReduced;
       rightPoint.y = (*rowIter)->row*BOX_SIZE*timesReduced;
       cvLine(columnsImg, leftPoint, rightPoint, cvScalar(255, 0, 255), 2);
     }
  }

  for (columnIter=columnLineList.begin(); columnIter!=columnLineList.end(); columnIter++)
  {
     if ((*columnIter)->height() > MIN_HEIGHT)
     {
       topPoint.x = (*columnIter)->column*BOX_SIZE*timesReduced;
       topPoint.y = (*columnIter)->top*BOX_SIZE*timesReduced;
       bottomPoint.x = (*columnIter)->column*BOX_SIZE*timesReduced;
       bottomPoint.y = (*columnIter)->bottom*BOX_SIZE*timesReduced;
       cvLine(columnsImg, topPoint, bottomPoint, cvScalar(0, 255, 0), 2);
     }
  }

  for (rowIter=rowLineList.begin(); rowIter!=rowLineList.end(); rowIter++)
  {
     if ((*rowIter)->width() > MIN_WIDTH)
     {
       leftPoint.x = (*rowIter)->left*BOX_SIZE*timesReduced;
       leftPoint.y = (*rowIter)->row*BOX_SIZE*timesReduced;
       rightPoint.x = (*rowIter)->right*BOX_SIZE*timesReduced;
       rightPoint.y = (*rowIter)->row*BOX_SIZE*timesReduced;
       cvLine(columnsImg, leftPoint, rightPoint, cvScalar(0, 255, 255), 2);
     }
  }

  columnLineList = findColumns(cleanedReducedImg, WHITE);
  rowLineList = findRows(cleanedReducedImg, WHITE);
  list<BoundingRectangle*> foundBoundingRectList = regionizeImage(cleanedReducedImg, BLACK);

  expandBoundingRectList(foundBoundingRectList);

  regionImg = cvCreateImage(cvSize(expandedImg->width, expandedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(expandedImg, expandedImg, expandedImg, NULL, regionImg);
  regionImg = displayBoundaries(regionImg, foundBoundingRectList, cvScalar(0, 0, 255), 1);

  cvNamedWindow("Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Regions", regionImg);
  cvMoveWindow("Regions", 530, 1);

  cvNamedWindow("Columns", CV_WINDOW_AUTOSIZE);
  cvShowImage("Columns", columnsImg);
  cvMoveWindow("Columns", 1045,1);

  cvWaitKey(0);

  cleanup();
}


IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;

  if (argc > 1)
    img = cvLoadImage(argv[argc-1], IPL_DEPTH_8U);
  else
    img = cvLoadImage(DEFAULT_IMAGE_NAME, IPL_DEPTH_8U);

  return img;
}

void cleanup()
{
  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  cvReleaseImage(&reducedImg);
  cvReleaseImage(&expandedImg);
  cvReleaseImage(&columnsImg);
  cvReleaseImage(&regionImg);
  cvDestroyWindow("Original");
  cvDestroyWindow("Reduced");
  // cvDestroyWindow("Expanded");
  cvDestroyWindow("Columns");
  cvDestroyWindow("Regions");
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val]\n");
    }
  }
}

void expandBoundingRectList(list<BoundingRectangle*> inRectangleList)
{
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    rectangle->top = rectangle->top * BOX_SIZE * timesReduced;
    rectangle->bottom = (rectangle->bottom * BOX_SIZE * timesReduced);
    rectangle->left = rectangle->left * BOX_SIZE* timesReduced;
    rectangle->right = (rectangle->right * BOX_SIZE * timesReduced);
  }
}

IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize)
{
  int width = inImage->width;
  int height = inImage->height;
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    if (rectangle->bottom >= height) rectangle->bottom = height-1;
    if (rectangle->right >= width) rectangle->right = width-1;
    cvRectangle(inImage, rectangle->topLeft(), rectangle->bottomRight(), inColor, inSize);
  }

  return inImage;
}


