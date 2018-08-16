reduce: main.o cleanImage.o reduceImage.o ColumnLine.o RowLine.o findParts.o
	g++ -bind_at_load `pkg-config --libs opencv` -o reduce main.o cleanImage.o reduceImage.o ColumnLine.o RowLine.o findParts.o

main.o: main.cpp reduceImage.h cleanImage.h
	g++ `pkg-config --cflags opencv` -c main.cpp

cleanImage.o: cleanImage.cpp cleanImage.h
	g++ `pkg-config --cflags opencv` -c cleanImage.cpp

ColumnLine.o: ColumnLine.cpp ColumnLine.h
	g++ `pkg-config --cflags opencv` -c ColumnLine.cpp

RowLine.o: RowLine.cpp RowLine.h
	g++ `pkg-config --cflags opencv` -c RowLine.cpp

findParts.o: findParts.cpp findParts.h
	g++ `pkg-config --cflags opencv` -c findParts.cpp

reduceImage.o: reduceImage.cpp reduceImage.h 
	g++ `pkg-config --cflags opencv` -c reduceImage.cpp

clean:
	rm -rf *.o reduce
