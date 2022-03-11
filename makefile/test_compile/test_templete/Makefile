objects:=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

main:$(objects)
	++ -o main -g $(objects)

.PHONY: clean

clean:
	-rm *.o main