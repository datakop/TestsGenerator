CXX = g++
CXXFLAGS = -Wall -g

main.exe: main.o \
	Generator.o \
	Templates.o 
	$(CXX) $(CXXFLAGS) -o main.exe \
		main.o Generator.o Templates.o 


main.o: main.cpp Generator.h Templates.h
Generator.o: Generator.h Templates.h
Templates.o: Templates.h


clean: 
	rm *.o
	rm *.exe