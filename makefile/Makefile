object=main.o speak.o

main:$(object)
	g++ -g $(object) -o main

compile: main.s speak.s
	g++ -c main.s -o main.o
	g++ -c speak.s -o speak.o


assemble: main.i speak.i
	g++ -S main.i -o main.s
	g++ -S speak.i -o speak.s

pre_compile: main.cpp speak.cpp
	g++ -E main.cpp -o main.i
	g++ -E speak.cpp -o speak.i



.PHONY: clean

clean:
	-rm *.i *.s *.o main