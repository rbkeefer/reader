frameChars: main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o ColumnLine.o RowLine.o findParts.o eliminateOverlappingRects.o
	g++ -bind_at_load `pkg-config --libs opencv` -o frameChars main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o ColumnLine.o RowLine.o findParts.o eliminateOverlappingRects.o

main.o: main.cpp reduceImage.h cleanImage.h pyramid.h
	g++ `pkg-config --cflags opencv` -c main.cpp

cleanImage.o: cleanImage.cpp cleanImage.h pyramid.h
	g++ `pkg-config --cflags opencv` -c cleanImage.cpp

reduceImage.o: reduceImage.cpp reduceImage.h utils.h pyramid.h
	g++ `pkg-config --cflags opencv` -c reduceImage.cpp

regionImage.o: regionImage.cpp regionImage.h utils.h BoundingRectangle.h pyramid.h
	g++ `pkg-config --cflags opencv` -c regionImage.cpp

utils.o: utils.cpp utils.h pyramid.h
	g++ `pkg-config --cflags opencv` -c utils.cpp

BoundingRectangle.o: BoundingRectangle.cpp BoundingRectangle.h pyramid.h
	g++ `pkg-config --cflags opencv` -c BoundingRectangle.cpp

ColumnLine.o: ColumnLine.cpp ColumnLine.h pyramid.h
	g++ `pkg-config --cflags opencv` -c ColumnLine.cpp

RowLine.o: RowLine.cpp RowLine.h pyramid.h
	g++ `pkg-config --cflags opencv` -c RowLine.cpp

findParts.o: findParts.cpp findParts.h pyramid.h
	g++ `pkg-config --cflags opencv` -c findParts.cpp

eliminateOverlappingRects.o: eliminateOverlappingRects.cpp eliminateOverlappingRects.h pyramid.h
	g++ `pkg-config --cflags opencv` -c eliminateOverlappingRects.cpp


clean:
	rm -rf *.o frameChars

