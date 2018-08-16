mergeRects: main.o utils.o BoundingRectangle.o mergeRectList.o
	g++ -bind_at_load `pkg-config --libs opencv` -o mergeRects main.o utils.o BoundingRectangle.o mergeRectList.o

main.o: main.cpp utils.h mergeRectList.h
	g++ `pkg-config --cflags opencv` -c main.cpp

mergeRectList.o: mergeRectList.cpp mergeRectList.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c mergeRectList.cpp

utils.o: utils.cpp utils.h
	g++ `pkg-config --cflags opencv` -c utils.cpp

BoundingRectangle.o: BoundingRectangle.cpp BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c BoundingRectangle.cpp

clean:
	rm -rf *.o mergeRects

