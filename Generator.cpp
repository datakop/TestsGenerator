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

	_generateHeader();
	_generateFunctionsBody();
	_generateMain();
}



void Generator::_generateHeader()
{

}
void Generator::_generateFunctionsBody()
{

}
void Generator::_generateMain()
{

}


Generator::~Generator()
{
	// Close generated file.
	_test_file.close();
}