frame: main.o cleanImage.o reduceImage.o regionImage.o utils.o BoundingRectangle.o combineTouchingRects.o frameImage.o mapImage.o eliminateOverlappingRects.o combineRects.o growRects.o
	g++ -bind_at_load `pkg-config --libs opencv` -o frame main.o cleanImage.o reduceImage.o regionImage.o combineTouchingRects.o utils.o BoundingRectangle.o frameImage.o mapImage.o eliminateOverlappingRects.o combineRects.o growRects.o

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

frameImage.o: frameImage.cpp frameImage.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c frameImage.cpp

combineRects.o: combineRects.cpp combineRects.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c combineRects.cpp

growRects.o: growRects.cpp growRects.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c growRects.cpp

combineTouchingRects.o: combineTouchingRects.cpp combineTouchingRects.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c combineTouchingRects.cpp

eliminateOverlappingRects.o: eliminateOverlappingRects.cpp eliminateOverlappingRects.h utils.h BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c eliminateOverlappingRects.cpp

utils.o: utils.cpp utils.h
	g++ `pkg-config --cflags opencv` -c utils.cpp

BoundingRectangle.o: BoundingRectangle.cpp BoundingRectangle.h
	g++ `pkg-config --cflags opencv` -c BoundingRectangle.cpp

clean:
	rm -rf *.o frame

