map: main.o cleanImage.o reduceImage.o regionImage.o mapImage.o utils.o BoundingRectangle.o 
	g++ -bind_at_load `pkg-config --libs opencv` -o map main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o mapImage.o 

main.o: main.cpp reduceImage.h cleanImage.h
	g++ `pkg-config --cflags opencv` -c main.cpp

cleanImage.o: cleanImage.cpp cleanImage.h
	g++ `pkg-config --cflags opencv` -c cleanImage.cpp

reduceImage.o: reduceImage.cpp reduceImage.h utils.h
	g++ `pkg-config --cflags opencv` -c reduceImage.cpp

regionImage.o: regionImage.cpp regionImage.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c regionImage.cpp

mapImage.o: mapImage.cpp mapImage.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c mapImage.cpp

utils.o: utils.cpp utils.h
	g++ `pkg-config --cflags opencv` -c utils.cpp

BoundingRectangle.o: BoundingRectangle.cpp BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c BoundingRectangle.cpp

clean:
	rm -rf *.o map

