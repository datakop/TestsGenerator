#include "Generator.h"

#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{

	int func_num = 100;

	// cout << "Welcome to test generator!" << endl;
	// cout << "Please, enter number of generated function: ";
	// cin >> func_num;

	Generator g(func_num , "t_file.c");
	g.generate();

	// cout << "\nTest is generated.!\n";

	return 0;
}