#!/bin/sh
g++ -ggdb `pkg-config opencv --cflags --libs` preprocessing.c -c
g++ -ggdb `pkg-config opencv --cflags --libs` preprocessing.o basicOCR.cpp -c
g++ -ggdb `pkg-config opencv --cflags --libs` preprocessing.o basicOCR.o main.c -o OCR
