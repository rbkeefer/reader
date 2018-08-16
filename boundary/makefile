boundary: main.o cleanImage.o reduceImage.o regionImage.o mapImage.o utils.o BoundingRectangle.o mergeRectList.o ColumnLine.o RowLine.o findParts.o
	g++ -bind_at_load `pkg-config --libs opencv` -o boundary main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o mapImage.o mergeRectList.o ColumnLine.o RowLine.o findParts.o

main.o: main.cpp reduceImage.h cleanImage.h pyramid.h
	g++ `pkg-config --cflags opencv` -c main.cpp

cleanImage.o: cleanImage.cpp cleanImage.h pyramid.h
	g++ `pkg-config --cflags opencv` -c cleanImage.cpp

reduceImage.o: reduceImage.cpp reduceImage.h utils.h pyramid.h
	g++ `pkg-config --cflags opencv` -c reduceImage.cpp

regionImage.o: regionImage.cpp regionImage.h utils.h BoundingRectangle.h pyramid.h
	g++ `pkg-config --cflags opencv` -c regionImage.cpp

mapImage.o: mapImage.cpp mapImage.h utils.h BoundingRectangle.h pyramid.h
	g++ `pkg-config --cflags opencv` -c mapImage.cpp

mergeRectList.o: mergeRectList.cpp mergeRectList.h utils.h BoundingRectangle.h pyramid.h
	g++ `pkg-config --cflags opencv` -c mergeRectList.cpp

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


clean:
	rm -rf *.o boundary

