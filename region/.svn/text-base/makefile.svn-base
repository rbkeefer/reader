region: main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o mergeRectList.o ColumnLine.o RowLine.o findParts.o
	g++ -bind_at_load `pkg-config --libs opencv` -o region main.o cleanImage.o reduceImage.o regionImage.o mergeRectList.o utils.o BoundingRectangle.o ColumnLine.o RowLine.o findParts.o

main.o: main.cpp reduceImage.h cleanImage.h
	g++ `pkg-config --cflags opencv` -c main.cpp

cleanImage.o: cleanImage.cpp cleanImage.h
	g++ `pkg-config --cflags opencv` -c cleanImage.cpp

reduceImage.o: reduceImage.cpp reduceImage.h utils.h
	g++ `pkg-config --cflags opencv` -c reduceImage.cpp

regionImage.o: regionImage.cpp regionImage.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c regionImage.cpp

mergeRectList.o: mergeRectList.cpp mergeRectList.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c mergeRectList.cpp

utils.o: utils.cpp utils.h
	g++ `pkg-config --cflags opencv` -c utils.cpp

BoundingRectangle.o: BoundingRectangle.cpp BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c BoundingRectangle.cpp

ColumnLine.o: ColumnLine.cpp ColumnLine.h
	g++ `pkg-config --cflags opencv` -c ColumnLine.cpp

RowLine.o: RowLine.cpp RowLine.h
	g++ `pkg-config --cflags opencv` -c RowLine.cpp

findParts.o: findParts.cpp findParts.h
	g++ `pkg-config --cflags opencv` -c findParts.cpp

clean:
	rm -rf *.o region

