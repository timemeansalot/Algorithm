# makefile v1.0: 定义变量
# 定义变量object，makefile中的变量跟c++中的宏定义很想

objects := main.o dog.o

main: $(objects)
	g++ -o main -g $(objects)
	ls $(objects)

.PHONY:clean

clean:
	-rm *.o main
