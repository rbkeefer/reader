#include "pyramid.h"
#include "cleanImage.h"
#include "reduceImage.h"
#include "regionImage.h"
#include "utils.h"
#include "mapImage.h"

// Local functions
void cleanup();
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
list<BoundingRectangle*> getWhiteRectList();
IplImage* displayBoundaries(IplImage* inImage,
                            list<BoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize);

// Constants
static char* DEFAULT_IMAGE_NAME = "/Users/rob/Research/Images/NewsPaper/NYpy128magClean.bmp";

// Local variables
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* regionImg;
IplImage* mappedImg;

int main(int argc, char** argv)
{
  int timesReduced = 0;
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);
  reducedImg =  cvCloneImage(cleanedImg);

  int originalWidth = reducedImg->width;
  
  while (reducedImg->width > 128)
  {
    reducedImg = reduceImage(reducedImg);
    timesReduced++; 
  }

  list<BoundingRectangle*> boundingRectList = regionizeImage(reducedImg, BLACK);
  regionImg = displayBoundaries(reducedImg, boundingRectList, cvScalar(0, 255, 0), 1);

  for (int reductionCounter = 0; reductionCounter < timesReduced; reductionCounter++)
  {
    boundingRectList = mapImage(boundingRectList);
  }

  mappedImg = displayBoundaries(cleanedImg, boundingRectList, cvScalar(0, 255, 0), 1);
  cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
  cvShowImage("Original", origImg);

  cvNamedWindow("First Reduced", CV_WINDOW_AUTOSIZE);
  cvShowImage("First Reduced", reducedImg);

  cvNamedWindow("Found Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Found Regions", regionImg);

  cvNamedWindow("Mapped Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Mapped Regions", mappedImg);

  cvWaitKey(0);

  cleanup();
}


IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList, CvScalar inColor, int inSize)
{
  IplImage* returnImg = cvCreateImage(cvSize(inImage->width, inImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inImage, inImage, inImage, NULL, returnImg);
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
     cvRectangle(returnImg, (*iter)->topLeft(), (*iter)->bottomRight(), inColor, inSize);
  }

  return returnImg;
}

IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;
  printf("Loading image ...\n");

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
  cvReleaseImage(&regionImg);
  cvReleaseImage(&mappedImg);

  cvDestroyWindow("Original");
  cvDestroyWindow("First Reduced");
  cvDestroyWindow("Found Regions");
  cvDestroyWindow("Mapped Regions");
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-accuracy") == 0)
    {
      accuracy = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-tolerance") == 0)
    {
      tolerance = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val] -tolerance [val] -accuracy [val]\n");
    }
  }
}



list<BoundingRectangle*> getWhiteRectList()
{
list<BoundingRectangle*>  returnList;
BoundingRectangle* r1 = new BoundingRectangle(0, 511, 0,4);
returnList.push_back(r1);



BoundingRectangle* r2 = new BoundingRectangle(0, 351, 5,5);
returnList.push_back(r2);

BoundingRectangle* r3 = new BoundingRectangle(0, 351, 6,6);
returnList.push_back(r3);

BoundingRectangle* r4 = new BoundingRectangle(0, 351, 7,7);
returnList.push_back(r4);



BoundingRectangle* r5 = new BoundingRectangle(0, 3, 8,8);
returnList.push_back(r5);

BoundingRectangle* r257 = new BoundingRectangle(0, 3, 9,498);
returnList.push_back(r257);

BoundingRectangle* r496 = new BoundingRectangle(0, 3, 499,499);
returnList.push_back(r496);



BoundingRectangle* r497 = new BoundingRectangle(0, 135, 500,500);
returnList.push_back(r497);

BoundingRectangle* r499 = new BoundingRectangle(0, 135, 501,502);
returnList.push_back(r499);

BoundingRectangle* r500 = new BoundingRectangle(0, 135, 503,503);
returnList.push_back(r500);




BoundingRectangle* r501 = new BoundingRectangle(0, 195, 504,504);
returnList.push_back(r501);

BoundingRectangle* r502 = new BoundingRectangle(0, 195, 505,505);
returnList.push_back(r502);




BoundingRectangle* r503 = new BoundingRectangle(0, 511, 506,511);
returnList.push_back(r503);






BoundingRectangle* r504 = new BoundingRectangle(68, 71, 8,8);
returnList.push_back(r504);

BoundingRectangle* r834 = new BoundingRectangle(68, 71, 9,338);
returnList.push_back(r834);

BoundingRectangle* r835 = new BoundingRectangle(68, 71, 339,339);
returnList.push_back(r835);




BoundingRectangle* r836 = new BoundingRectangle(68, 351, 340,340);
returnList.push_back(r836);

BoundingRectangle* r838 = new BoundingRectangle(68, 351, 341,342);
returnList.push_back(r838);

BoundingRectangle* r839 = new BoundingRectangle(68, 351, 343,343);
returnList.push_back(r839);




BoundingRectangle* r840 = new BoundingRectangle(68, 511, 344,348);
returnList.push_back(r840);




BoundingRectangle* r841 = new BoundingRectangle(68, 71, 349,349);
returnList.push_back(r841);

BoundingRectangle* r910 = new BoundingRectangle(68, 71, 350,418);
returnList.push_back(r910);

BoundingRectangle* r911 = new BoundingRectangle(68, 71, 419,419);
returnList.push_back(r911);




BoundingRectangle* r912 = new BoundingRectangle(68, 171, 420,420);
returnList.push_back(r912);

BoundingRectangle* r916 = new BoundingRectangle(68, 171, 421,424);
returnList.push_back(r916);

BoundingRectangle* r917 = new BoundingRectangle(68, 171, 425,425);
returnList.push_back(r917);




BoundingRectangle* r918 = new BoundingRectangle(68, 511, 426,432);
returnList.push_back(r918);




BoundingRectangle* r919 = new BoundingRectangle(68, 71, 433,433);
returnList.push_back(r919);

BoundingRectangle* r980 = new BoundingRectangle(68, 71, 434,494);
returnList.push_back(r980);

BoundingRectangle* r981 = new BoundingRectangle(68, 71, 495,495);
returnList.push_back(r981);




BoundingRectangle* r982 = new BoundingRectangle(68, 107, 496,496);
returnList.push_back(r982);

BoundingRectangle* r984 = new BoundingRectangle(68, 107, 497,498);
returnList.push_back(r984);

BoundingRectangle* r985 = new BoundingRectangle(68, 107, 499,499);
returnList.push_back(r985);



// RECTANGLE 15
BoundingRectangle* r986 = new BoundingRectangle(104, 107, 433,433);
returnList.push_back(r986);

BoundingRectangle* r1047 = new BoundingRectangle(104, 107, 434,494);
returnList.push_back(r1047);

BoundingRectangle* r1048 = new BoundingRectangle(104, 107, 495,495);
returnList.push_back(r1048);




BoundingRectangle* r1049 = new BoundingRectangle(112, 115, 349,349);
returnList.push_back(r1049);

BoundingRectangle* r1118 = new BoundingRectangle(112, 115, 350,418);
returnList.push_back(r1118);

BoundingRectangle* r1119 = new BoundingRectangle(112, 115, 419,419);
returnList.push_back(r1119);




BoundingRectangle* r1120 = new BoundingRectangle(124, 135, 433,433);
returnList.push_back(r1120);

BoundingRectangle* r1137 = new BoundingRectangle(124, 135, 434,450);
returnList.push_back(r1137);

BoundingRectangle* r1138 = new BoundingRectangle(124, 135, 451,451);
returnList.push_back(r1138);




BoundingRectangle* r1139 = new BoundingRectangle(124, 127, 452,452);
returnList.push_back(r1139);

BoundingRectangle* r1169 = new BoundingRectangle(124, 127, 453,482);
returnList.push_back(r1169);

BoundingRectangle* r1170 = new BoundingRectangle(124, 127, 483,483);
returnList.push_back(r1170);




BoundingRectangle* r1171 = new BoundingRectangle(124, 135, 484,484);
returnList.push_back(r1171);

BoundingRectangle* r1185 = new BoundingRectangle(124, 135, 485,498);
returnList.push_back(r1185);

BoundingRectangle* r1186 = new BoundingRectangle(124, 135, 499,499);
returnList.push_back(r1186);




BoundingRectangle* r1187 = new BoundingRectangle(132, 135, 452,452);
returnList.push_back(r1187);

BoundingRectangle* r1217 = new BoundingRectangle(132, 135, 453,482);
returnList.push_back(r1217);

BoundingRectangle* r1218 = new BoundingRectangle(132, 135, 483,483);
returnList.push_back(r1218);



// RECTANGLE 21
BoundingRectangle* r1219 = new BoundingRectangle(144, 171, 349,349);
returnList.push_back(r1219);

BoundingRectangle* r1220 = new BoundingRectangle(144, 171, 350,350);
returnList.push_back(r1220);

BoundingRectangle* r1221 = new BoundingRectangle(144, 171, 351,351);
returnList.push_back(r1221);




BoundingRectangle* r1222 = new BoundingRectangle(144, 155, 352,352);
returnList.push_back(r1222);

BoundingRectangle* r1232 = new BoundingRectangle(144, 155, 353,362);
returnList.push_back(r1232);

BoundingRectangle* r1233 = new BoundingRectangle(144, 155, 363,363);
returnList.push_back(r1233);




BoundingRectangle* r1234 = new BoundingRectangle(144, 147, 364,364);
returnList.push_back(r1234);

BoundingRectangle* r1260 = new BoundingRectangle(144, 147, 365,390);
returnList.push_back(r1260);

BoundingRectangle* r1261 = new BoundingRectangle(144, 147, 391,391);
returnList.push_back(r1261);




BoundingRectangle* r1262 = new BoundingRectangle(144, 155, 392,392);
returnList.push_back(r1262);

BoundingRectangle* r1276 = new BoundingRectangle(144, 155, 393,406);
returnList.push_back(r1276);

BoundingRectangle* r1277 = new BoundingRectangle(144, 155, 407,407);
returnList.push_back(r1277);




BoundingRectangle* r1278 = new BoundingRectangle(144, 171, 408,408);
returnList.push_back(r1278);

BoundingRectangle* r1288 = new BoundingRectangle(144, 171, 409,418);
returnList.push_back(r1288);

BoundingRectangle* r1289 = new BoundingRectangle(144, 171, 419,419);
returnList.push_back(r1289);





// RECTANGLE 26
BoundingRectangle* r1290 = new BoundingRectangle(144, 155, 433,433);
returnList.push_back(r1290);

BoundingRectangle* r1299 = new BoundingRectangle(144, 155, 434,442);
returnList.push_back(r1299);

BoundingRectangle* r1300 = new BoundingRectangle(144, 155, 443,443);
returnList.push_back(r1300);




BoundingRectangle* r1301 = new BoundingRectangle(144, 147, 444,444);
returnList.push_back(r1301);

BoundingRectangle* r1341 = new BoundingRectangle(144, 147, 445,484);
returnList.push_back(r1341);

BoundingRectangle* r1342 = new BoundingRectangle(144, 147, 485,485);
returnList.push_back(r1342);





// RECTANGLE 28
BoundingRectangle* r1343 = new BoundingRectangle(144, 155, 486,486);
returnList.push_back(r1343);

BoundingRectangle* r1359 = new BoundingRectangle(144, 155, 487,502);
returnList.push_back(r1359);

BoundingRectangle* r1360 = new BoundingRectangle(144, 155, 503,503);
returnList.push_back(r1360);



return returnList;

// RECTANGLE 29
BoundingRectangle* r1361 = new BoundingRectangle(152, 155, 364,364);
returnList.push_back(r1361);

BoundingRectangle* r1429 = new BoundingRectangle(152, 155, 365,484);
returnList.push_back(r1429);

BoundingRectangle* r1430 = new BoundingRectangle(152, 155, 485,485);
returnList.push_back(r1430);




// RECTANGLE 30
BoundingRectangle* r1431 = new BoundingRectangle(168, 171, 352,352);
returnList.push_back(r1431);

BoundingRectangle* r1485 = new BoundingRectangle(168, 171, 353,406);
returnList.push_back(r1485);

BoundingRectangle* r1486 = new BoundingRectangle(168, 171, 407,407);
returnList.push_back(r1486);





BoundingRectangle* r1487 = new BoundingRectangle(184, 195, 433,433);
returnList.push_back(r1487);

BoundingRectangle* r1556 = new BoundingRectangle(184, 195, 434,502);
returnList.push_back(r1556);

BoundingRectangle* r1557 = new BoundingRectangle(184, 195, 503,503);
returnList.push_back(r1557);






BoundingRectangle* r1558 = new BoundingRectangle(338, 351, 8,8);
returnList.push_back(r1558);

BoundingRectangle* r1848 = new BoundingRectangle(338, 351, 9,298);
returnList.push_back(r1848);

BoundingRectangle* r1849 = new BoundingRectangle(338, 351, 299,299);
returnList.push_back(r1849);




BoundingRectangle* r1850 = new BoundingRectangle(338, 343, 300,300);
returnList.push_back(r1850);

BoundingRectangle* r1888 = new BoundingRectangle(338, 343, 301,338);
returnList.push_back(r1888);

BoundingRectangle* r1889 = new BoundingRectangle(338, 343, 339,339);
returnList.push_back(r1889);





BoundingRectangle* r1890 = new BoundingRectangle(348, 351, 300,300);
returnList.push_back(r1890);

BoundingRectangle* r1928 = new BoundingRectangle(348, 351, 301,338);
returnList.push_back(r1928);

BoundingRectangle* r1929 = new BoundingRectangle(348, 351, 339,339);
returnList.push_back(r1929);




BoundingRectangle* r1930 = new BoundingRectangle(388, 391, 5,5);
returnList.push_back(r1930);

BoundingRectangle* r2003 = new BoundingRectangle(388, 391, 6,78);
returnList.push_back(r2003);

BoundingRectangle* r2004 = new BoundingRectangle(388, 391, 79,79);
returnList.push_back(r2004);




BoundingRectangle* r2005 = new BoundingRectangle(388, 407, 80,80);
returnList.push_back(r2005);

BoundingRectangle* r2006 = new BoundingRectangle(388, 407, 81,82);
returnList.push_back(r2006);

BoundingRectangle* r2008 = new BoundingRectangle(388, 407, 83,83);
returnList.push_back(r2008);




BoundingRectangle* r2009 = new BoundingRectangle(388, 511, 84,88);
returnList.push_back(r2009);



BoundingRectangle* r2010 = new BoundingRectangle(388, 419, 89,89);
returnList.push_back(r2010);

BoundingRectangle* r2011 = new BoundingRectangle(388, 419, 90,90);
returnList.push_back(r2011);

BoundingRectangle* r2012 = new BoundingRectangle(388, 419, 91,91);
returnList.push_back(r2012);



BoundingRectangle* r2013 = new BoundingRectangle(388, 391, 92,92);
returnList.push_back(r2013);

BoundingRectangle* r2262 = new BoundingRectangle(388, 391, 93,341);
returnList.push_back(r2262);

BoundingRectangle* r2263 = new BoundingRectangle(388, 511, 342,347);
returnList.push_back(r2263);




BoundingRectangle* r2264 = new BoundingRectangle(404, 447, 5,5);
returnList.push_back(r2264);

BoundingRectangle* r2269 = new BoundingRectangle(404, 447, 6,10);
returnList.push_back(r2269);

BoundingRectangle* r2270 = new BoundingRectangle(404, 447, 11,11);
returnList.push_back(r2270);




BoundingRectangle* r2271 = new BoundingRectangle(404, 407, 12,12);
returnList.push_back(r2271);

BoundingRectangle* r2337 = new BoundingRectangle(404, 407, 13,78);
returnList.push_back(r2337);

BoundingRectangle* r2338 = new BoundingRectangle(404, 407, 79,79);
returnList.push_back(r2338);




BoundingRectangle* r2339 = new BoundingRectangle(404, 419, 92,92);
returnList.push_back(r2339);

BoundingRectangle* r2417 = new BoundingRectangle(404, 419, 93,170);
returnList.push_back(r2417);

BoundingRectangle* r2418 = new BoundingRectangle(404, 419, 171,171);
returnList.push_back(r2418);





BoundingRectangle* r2419 = new BoundingRectangle(404, 511, 172,176);
returnList.push_back(r2419);





BoundingRectangle* r2420 = new BoundingRectangle(404, 407, 177,177);
returnList.push_back(r2420);

BoundingRectangle* r2497 = new BoundingRectangle(404, 407, 178,254);
returnList.push_back(r2497);

BoundingRectangle* r2498 = new BoundingRectangle(404, 407, 255,255);
returnList.push_back(r2498);





BoundingRectangle* r2499 = new BoundingRectangle(404, 511, 256,260);
returnList.push_back(r2499);





BoundingRectangle* r2500 = new BoundingRectangle(404, 407, 261,261);
returnList.push_back(r2500);

BoundingRectangle* r2579 = new BoundingRectangle(404, 407, 262,340);
returnList.push_back(r2579);

BoundingRectangle* r2580 = new BoundingRectangle(404, 407, 341,341);
returnList.push_back(r2580);




BoundingRectangle* r2581 = new BoundingRectangle(436, 447, 12,12);
returnList.push_back(r2581);

BoundingRectangle* r2651 = new BoundingRectangle(436, 447, 13,82);
returnList.push_back(r2651);

BoundingRectangle* r2652 = new BoundingRectangle(436, 447, 83,83);
returnList.push_back(r2652);

return returnList;
}



