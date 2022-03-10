objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

main: $(objects)
	g++ -o main -g $(objects)
	ls $(objects)

.PHONY:clean

clean:
	-rm *.o main
