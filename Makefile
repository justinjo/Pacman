###############################################################################
# Makefile                                                                    #
# For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           #
###############################################################################

all: pacman.o ghost.o game.o main.o termfuncs.o dot.o boulder.o
	clang++ -Wall -Wextra -g pacman.o ghost.o game.o main.o termfuncs.o \
			      dot.o boulder.o -o pacman
	chmod g+rwx pacman

pacman.o: pacman.cpp pacman.h constants.h termfuncs.h
	clang++ -c -Wall -Wextra pacman.cpp
	chmod g+rw pacman.o

ghost.o: ghost.cpp ghost.h constants.h termfuncs.h
	clang++ -c -Wall -Wextra ghost.cpp
	chmod g+rw ghost.o

game.o: game.cpp *.h
	clang++ -c -Wall -Wextra game.cpp
	chmod g+rw game.o

main.o: main.cpp constants.h termfuncs.h
	clang++ -c -Wall -Wextra main.cpp
	chmod g+rw main.o

boulder.o: boulder.cpp boulder.h termfuncs.h constants.h
	clang++ -c -Wall -Wextra boulder.cpp
	chmod g+rw boulder.o

dot.o: dot.cpp dot.h constants.h termfuncs.h
	clang++ -c -Wall -Wextra dot.cpp
	chmod g+rw dot.o

termfuncs.o: termfuncs.cpp termfuncs.h
	clang++ -c -Wall -Wextra termfuncs.cpp
	chmod g+rw termfuncs.o

clean:
	rm *.o pacman
