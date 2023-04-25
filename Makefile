CFLAGS=-c -Wall -Werror -Wextra -std=c++20

all: start clean

start: main.o controller.o hunteronlines.o gameboard.o player.o hunteronlines.o position.o exceptions.o
	g++ main.o controller.o hunteronlines.o gameboard.o player.o position.o exceptions.o -o program.exe

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

controller.o: controller.cpp
	g++ $(CFLAGS) controller.cpp

hunteronlines.o: hunteronlines.cpp
	g++ $(CFLAGS) hunteronlines.cpp

gameboard.o: gameboard.cpp
	g++ $(CFLAGS) gameboard.cpp

player.o: player.cpp
	g++ $(CFLAGS) player.cpp

hunteronlines.o: hunteronlines.cpp
	g++ $(CFLAGS) hunteronlines.cpp

position.o: position.cpp
	g++ $(CFLAGS) position.cpp

exceptions.o: exceptions.cpp
	g++ $(CFLAGS) exceptions.cpp

clean:
	del *.o