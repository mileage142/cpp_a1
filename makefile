#C++ Datastructures Makefile

# Miles Thomas s3494949
#
#
#
#


all: strlist.o user.o options.o 
		g++ -o test_datastructures options.o user.o strlist.o -lboost_program_options -g

strlist.o: strlist.cpp strlist.h
		g++ -c -Wall -pedantic -std=c++14 strlist.cpp

user.o: user.cpp user.h
		g++ -c -Wall -pedantic -std=c++14 user.cpp

options.o: options.cpp options.h
		g++ -c -Wall -pedantic -std=c++14  options.cpp

clean:
		rm -rf *o test_datastructures *out.txt
