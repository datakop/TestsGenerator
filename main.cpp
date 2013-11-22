#include "Generator.h"

#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{

	int func_num = 101,
		iterations = 0;

	cout << "Welcome to test generator!" << endl;
	cout << "Please, enter number of iterations: ";
	cin >> iterations;

	Generator g(func_num , "t_file.c"); 
	g.generate(iterations);				// Run Generator

	cout << "\nTest is generated!\n";

	return 0;
}