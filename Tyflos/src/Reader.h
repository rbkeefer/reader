/*
 * Reader.h
 *
 */

#ifndef READER_H_
#define READER_H_

#include "/opt/local/include/opencv/cv.h"
#include "/opt/local/include/opencv/cvaux.h"
#include "/opt/local/include/opencv/highgui.h"

#include <list>
using namespace std;

#define BOX_SIZE 2

#define LINE_TYPE 3
#define IMAGE_TYPE 4
#define HEADLINE_TYPE 1
#define CONTENT_TYPE 2

#define BLACK 0x00
#define WHITE 0xFF

#define OFF 0
#define ON 1

#define AUTOMATIC_MODE 1
#define MANUAL_MODE 2

const CvScalar COLOR_BLUE = cvScalar(255, 0, 0);
const CvScalar COLOR_RED = cvScalar(0, 0, 255);
const CvScalar COLOR_GREEN = cvScalar(0, 255, 0);
const CvScalar COLOR_YELLOW = cvScalar(0, 255, 255);
const CvScalar COLOR_PURPLE = cvScalar(255, 0, 255);

const int THIN_LINE = 1;
const int THICK_LINE = 2;

#endif /* READER_H_ */
