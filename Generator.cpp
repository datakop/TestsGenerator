#include "Templates.h"
#include "Generator.h"

#include <iostream>

using namespace std;

Generator::Generator(int func_num, const char* file_name)
{
	_func_num = func_num;
	_test_file.open(file_name);
}

void Generator::generate()
{
	_test_file << "Hello!";

	generateHeader();
	generateFunctionsBody();
	generateMain();
}













Generator::~Generator()
{
	// Close generated file.
	_test_file.close();
	cout << "Kill Generator! "<< _func_num << endl;
}