#include "Template.h"
#include "Generator.h"

#include <iostream>

using namespace std;

Generator::Generator(int func_num, const char* file_name)
{
	_func_num = func_num;
	_test_file.open(file_name);

	_template = new Template();
}

void Generator::generate()
{
	_generateHeader();
	_generateFunctionsBody();
	_generateMain();
}



void Generator::_generateHeader()
{

}
void Generator::_generateFunctionsBody()
{
	cout << _template->getFunctionByNum(10) << endl;
}
void Generator::_generateMain()
{

}


Generator::~Generator()
{
	// Close generated file.
	_test_file.close();
	delete _template;

	cout << "Destroy Generator." << endl; 
}