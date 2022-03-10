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

static: say.cpp sayhello.cpp
	g++ -c say.cpp -o say.o
	g++ -c sayhello.cpp -o sayhello.o
	ar -r say.a say.o sayhello.o

use_static: saymain.cpp say.a
	g++ -g saymain.cpp say.a -o main

.PHONY: clean

clean:
	-rm *.i *.s *.o main