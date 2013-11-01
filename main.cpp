#include "Generator.h"

#include <iostream>



using namespace std;




int main(int argc, char const *argv[])
{
	Generator g(10, "t_file.c");
	g.generate();
	return 0;
}