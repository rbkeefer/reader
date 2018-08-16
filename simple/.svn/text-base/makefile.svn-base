simple: simple.o
	g++ -bind_at_load `pkg-config --libs opencv` simple.o -o simple

simple.o: simple.c
	g++ `pkg-config --cflags opencv` -c simple.c
