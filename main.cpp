#include "Generator.h"

#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{

	int func_num = 101;

	// cout << "Welcome to test generator!" << endl;
	// cout << "Please, enter number of generated function: ";
	// cin >> func_num;

	Generator g(func_num , "t_file.c");
	g.generate(1000);

	// cout << "\nTest is generated.!\n";

	return 0;
}