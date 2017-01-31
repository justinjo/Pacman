# Terminal-Pacman

Pacman-inspired game played on the terminal command line.

## Table of Contents  
* [Terminal-Pacman](#terminal-pacman)
* [Table of Contents](#table-of-contents)  
* [Build Instructions](#build-instructions)  
* [Directory Structure](#directory-structure)

Build Instructions
======
To build and play the game, follow the steps as outlined below:

* Clone the [source repository](https://github.com/justinjo/Terminal-Pacman) from GitHub.
	* Download as zip and expand.
	* Enter `git clone https://github.com/justinjo/Terminal-Pacman` on the command line.
* Change into the Terminal-Pacman directory.
	* Ex. `cd Terminal-Pacman`
* Type `make` to build the executable.
* Type `./pacman` to run and play the game.
* To delete the executable and object files, type `make clean`


Directory Structure
======
```
Terminal-Pacman/
+-- README.md
+-- Makefile
+-- boulder.cpp
+-- boulder.h
+-- constants.h
+-- dot.cpp
+-- dot.h
+-- game.cpp
+-- game.h
+-- ghost.cpp
+-- ghost.h
+-- main.cpp
+-- pacman.cpp
+-- pacman.h
+-- termfuncs.cpp
+-- termfuncs.h
```