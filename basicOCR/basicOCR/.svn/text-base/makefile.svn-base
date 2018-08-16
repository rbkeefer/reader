OCR: main.o basicOCR.o preprocessing.o test.o
	g++ -bind_at_load `pkg-config --libs opencv` -o OCR main.o basicOCR.o preprocessing.o test.o

main.o: main.c
	g++ `pkg-config --cflags opencv` -c main.c

basicOCR.o: basicOCR.cpp basicOCR.h
	g++ `pkg-config --cflags opencv` -c basicOCR.cpp

preprocessing.o: preprocessing.c
	g++ `pkg-config --cflags opencv` -c preprocessing.c

test.o: test.c
	g++ `pkg-config --cflags opencv` -c test.c
