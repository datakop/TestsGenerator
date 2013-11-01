#include "Generator.h"

#include <iostream>



using namespace std;




int main(int argc, char const *argv[])
{
	Generator g(10, "file_asdsada.c");
	g.generate();
	return 0;
}