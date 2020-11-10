# Tyflos Reader
Tyflos - OCR, Document Image Processing Pipeline, Data, and Tests

Document image processing pipeline for making an image of a newspaper article available to a listener through text to speech processing.

## Requirements
* OpenCV
* Matlab

## Dewarping
The dewarping and perspective correction code is in Matlab. This was run on Matlab 2010a and does not require any other libraries.

* docReader.m - main file that will read a jpg image and process it. A few configurable parameters are defined at the top of the file
* Most of the rest of the files are self explanatory, except for the getBookHalfs.m This file contains code that will support the correction of an image of a book, and separates the image into two pages. This file is not needed for newspaper images.

## Reader</p>
This directory contains the files needed to cleanup run the segmentation, headline identification, and aggregation portion of the pipeline. This code is in C++ with OpenCV. This directory structure was created as an Eclipse workspace. Hopefully you would be able to copy the directory into your Eclipse workspace directory and it should compile and run from Eclipse.

Note that the code assumes a 640x480 image. Some of the parameters need to be changed for other sized images.

The WSJCurl1.jpg file is a good example of an image that can be run in through the dewarping code and then through the segmentation code.
