
#include <iostream>

#include "Registration.h"
#include "RkBoundingRectangle.h"
#include "RkArticle.h"
#include "RkSegment.h"
#include "RkFrames.h"
#include "RkUtils.h"


// *** TEST CLASSES ***
void testRkBoundingRect();
void testRkFrames();
void testRkUtils();
void testRkArticle();

// *** Local functions ***
void processArguments(int argc, char** argv);
list<RkArticle*> getArticleList(const char* inFileName);
void dumpArticleList(list<RkArticle*> inArticleList, const char* inFileName);


// Constants

// Local variables
const char* referenceFileName;
const char* targetFileName;


int main(int argc, char** argv) {
  int counter;
  RkArticle* target;
  RkArticle* reference;
  list<RkArticle*>::iterator referenceIter;
  list<RkArticle*>::iterator targetIter;

  /* RUN TESTS FIRST */
  testRkBoundingRect();
  testRkArticle();
  testRkUtils();
  testRkFrames();

// exit(0);

  /* MAIN */
  processArguments(argc, argv);

  printf("\nProcessing files: %s : %s \n\n", referenceFileName, targetFileName);
  list<RkArticle*> referenceDocument = getArticleList(referenceFileName);
  list<RkArticle*> targetDocument = getArticleList(targetFileName);

  printf("TGT #:");
  for (counter = 0; counter < (int)targetDocument.size(); counter++)
	  printf("                                             %d", counter+1);
  printf("\n");

  for (referenceIter=referenceDocument.begin(); referenceIter!=referenceDocument.end(); referenceIter++)
  {
	reference = (*referenceIter);
	reference->info();
	for (targetIter=targetDocument.begin(); targetIter!=targetDocument.end(); targetIter++)
	{
	  target = (*targetIter);
	  printf("     |     "); target->info();
	}
	printf("\n");
  }

  printf("\n");


  int refNumber;
  int simRefNumber;
  float refHeight;
  float refWidth;
  float refNumColumns;
  float refAvgDistance;

  int tgtNumber;
  int simTgtNumber;
  float tgtHeight;
  float tgtWidth;
  float tgtNumColumns;
  float tgtAvgDistance;

  float s1, s2, s3;
  float similarity = 0.0;
  float lowSimilarity = 1000.0;

  printf("TGT #:");
  for (counter = 0; counter < (int)targetDocument.size(); counter++)
	  printf("               %d", counter+1);
  printf("\n");

  refNumber = 0;
  for (referenceIter=referenceDocument.begin(); referenceIter!=referenceDocument.end(); referenceIter++)
  {
	refNumber++; printf("Ref %d:", refNumber);
	reference = (*referenceIter);
	refHeight = reference->height();
	refWidth = reference->width();
	refNumColumns = reference->numberOfColumns();
	refAvgDistance = reference->distBetweenColumns();

	tgtNumber = 0;
    for (targetIter=targetDocument.begin(); targetIter!=targetDocument.end(); targetIter++)
    {
      tgtNumber++;
	  target = (*targetIter);
	  tgtHeight = target->height();
	  tgtWidth = target->width();
	  tgtNumColumns = target->numberOfColumns();
	  tgtAvgDistance = target->distBetweenColumns();

	  s1 = abs((refHeight/refWidth) - (tgtHeight/tgtWidth));
	  s2 = abs(refNumColumns - tgtNumColumns);
	  s3 = abs(refAvgDistance - tgtAvgDistance);

	  similarity = s1 * (s2+s3);
      printf("          [%.2f]", similarity);

      if ((similarity > 0.0) && (similarity < lowSimilarity))
      {
    	lowSimilarity = similarity;
    	simRefNumber = refNumber;
    	simTgtNumber = tgtNumber;
      }
    }

    printf("\n");
  }

  printf("Most Similar: Reference:[%d] with Target:[%d]\n", simRefNumber, simTgtNumber);

}

void processArguments(int argc, char** argv)
{
  if (argc < 2)
  {
    printf("Usage referenceImage targetImage\n \n");
  }

  string* outFileName = new string(argv[argc-2]);
  referenceFileName = outFileName->c_str();

  outFileName = new string(argv[argc-1]);
  targetFileName = outFileName->c_str();

}

list<RkArticle*> getArticleList(const char* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  int* numColumns = new int;
  int columnCounter;

  list<RkArticle*> articleList;
  RkArticle* tmpArticle;
  RkBoundingRectangle* tmpRect;

  FILE* articleFile;
  articleFile = fopen(inFileName, "r");

  while ( ! feof (articleFile) )
  {
	fscanf(articleFile, "%d,%d,%d,%d,%d\n", top, left, bottom, right, numColumns);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	tmpArticle = new RkArticle();
	tmpArticle->headline = new RkSegment(tmpRect,1);

	for (columnCounter=0; columnCounter < *numColumns; columnCounter++)
	{
		fscanf(articleFile, "%d,%d,%d,%d\n", top, left, bottom, right);
		tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
		tmpArticle->columns.push_back(new RkSegment(tmpRect, 2));
	}

	articleList.push_back(tmpArticle);
  }

  fclose(articleFile);
  return articleList;
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

