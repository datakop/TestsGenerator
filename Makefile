CXX = g++ $(CXXFLAGS) $(INCLUDES) 

CXXFLAGS = -std=c++0x -Wall -g -D_GLIBCXX_DEBUG  -O3

INCLUDES = -I/vdtools/git/ctemplate/install/include \
	-I/vdtools/opt/boost_1_55_0b1/install/include 

LIBS = -L/vdtools/git/ctemplate/install/lib \
	-L/vdtools/opt/boost_1_55_0b1/install/lib \
	-lctemplate_nothreads 


main.exe: main.o \
	Generator.o \
	Template.o 
	$(CXX) -o main.exe \
		main.o Generator.o Template.o  $(LIBS)


main.o: main.cpp Generator.h Template.h
Generator.o: Generator.h Template.h
Template.o: Template.h


clean: 
	-rm *.o
	-rm *.exe
	-rm t_file.c