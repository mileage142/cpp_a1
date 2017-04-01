#C++ Datastructures Makefile

# Miles Thomas s3494949
#
#
#
#


all: options.o user.o strlist.o
		g++ -o datastruct options.o user.o strlist.o -lboost_program_options -g

options.o: options.cpp options.h
		g++ -c -Wall -pedantic -std=c++14  options.cpp

user.o: user.cpp user.h
		g++ -c -Wall -pedantic -std=c++14 user.cpp

strlist.o: strlist.cpp strlist.h
		g++ -c -Wall -pedantic -std=c++14 strlist.cpp

clean:
		rm -rf *o datastruct
