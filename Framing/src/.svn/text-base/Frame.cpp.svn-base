
#include <iostream>

#include "Frame.h"
#include "RkBoundingRectangle.h"
#include "RkCharacter.h"
#include "RkTextFrame.h"
#include "RkSegment.h"
#include "RkArticle.h"
#include "RkUtils.h"
#include "RkSize.h"
#include "RkRegions.h"
#include "RkFrames.h"


// *** TEST CLASSES ***
void testRkColumn();
void testRkRow();
void testRkBoundingRect();
void testRkRegions();
void testRkFrames();
void testRkUtils();
void testRkCharacter();
void testRkTextFrame();
void testRkArticle();
void testRkSegment();

// *** Local functions ***
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
IplImage* cleanImage(IplImage* inImage, int inThreshold);
list<RkSegment*> getSegmentList(const char* inFileName);
list<RkBoundingRectangle*> getRectangleList(const char* inFileName);
void dumpArticleList(list<RkArticle*> inArticleList, const char* inFileName);
const char* inputFileName(int argc, char** argv);
const char* outFileName(int argc, char** argv);
void cleanup();


// Constants
int threshold = 128;

// Local variables
string* imageFileName = new string("/Users/rob/Research/Images/test/CloseTest.bmp");
IplImage* origImg;
IplImage* cleanedImg;
IplImage* articleImg;


int main(int argc, char** argv) {
  /* RUN TESTS FIRST */
  testRkColumn();
  testRkRow();
  testRkBoundingRect();
  testRkCharacter();
  testRkTextFrame();
  testRkArticle();
  testRkUtils();
  testRkRegions();
  testRkSegment();
  testRkFrames();

// exit(0);

  /* MAIN */
/* */
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);

  list<RkSegment*> regionList = getSegmentList(inputFileName(argc, argv));

  list<RkArticle*> articleList = groupArticles(regionList);

  dumpArticleList(articleList, outFileName(argc, argv));

  articleImg = cvCreateImage(cvSize(origImg->width, origImg->height), IPL_DEPTH_8U, 3);
  cvMerge(origImg, origImg, origImg, NULL, articleImg);
  // articleImg = displayBoundaries(articleImg, regionList, cvScalar(255, 0, 255), 1);
  articleImg = displayBoundaries(articleImg, articleList, cvScalar(0, 0, 255), 2);
  cvNamedWindow("Articles", CV_WINDOW_AUTOSIZE);
  cvShowImage("Articles", articleImg);

  cvWaitKey(0);
  cleanup();
/* */
}

void cleanup()
{
  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  cvReleaseImage(&articleImg);

  cvDestroyWindow("Articles");
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

IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;

  if (argc > 1)
  {
    imageFileName = new string(argv[argc-1]);
  }

  img = cvLoadImage(imageFileName->c_str(), IPL_DEPTH_8U);

  return img;
}

list<RkSegment*> getSegmentList(const char* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  int* segmentType = new int;
  list<RkSegment*> segmentList;
  RkBoundingRectangle* tmpRect;

  FILE* segmentFile;
  segmentFile = fopen(inFileName, "r");

  while ( ! feof (segmentFile) )
  {
	fscanf(segmentFile, "%d,%d,%d,%d,%d\n", top, left, bottom, right, segmentType);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	segmentList.push_back(new RkSegment(tmpRect, *segmentType));
  }

  fclose(segmentFile);
  return segmentList;
}

void dumpArticleList(list<RkArticle*> inArticleList, const char* inFileName)
{
  RkArticle* article;
  list<RkArticle*>::iterator articleIter;

  FILE* framesFile;
  framesFile = fopen(inFileName, "w");

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
	  article = (*articleIter);
	  article->printString(framesFile);
  }

  fclose(framesFile);
}

const char* inputFileName(int argc, char** argv)
{
  string* outFileName;
  if (argc > 1)
  {
	outFileName = new string(argv[argc-1]);
    outFileName->append(".Classified.txt");
  }

  return outFileName->c_str();
}

const char* outFileName(int argc, char** argv)
{
  string* outFileName;
  if (argc > 1)
  {
	outFileName = new string(argv[argc-1]);
    outFileName->append(".Frames.txt");
  }

  return outFileName->c_str();
}
