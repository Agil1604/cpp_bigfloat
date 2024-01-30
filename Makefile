all: bigfloat.o bigfloat.exe

CC := g++

bigfloat.exe: bigfloat.h bigfloat.cpp
	$(CC) -m32 bigfloat.cpp -o bigfloat.exe

clean:
	rm bigfloat.exe
