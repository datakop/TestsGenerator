CXX = g++
CXXFLAGS = -Wall -g -D_GLIBCXX_DEBUG

main.exe: main.o \
	Generator.o \
	Template.o 
	$(CXX) $(CXXFLAGS) -o main.exe \
		main.o Generator.o Template.o 


main.o: main.cpp Generator.h Template.h
Generator.o: Generator.h Template.h
Template.o: Template.h


clean: 
	rm *.o
	rm *.exe