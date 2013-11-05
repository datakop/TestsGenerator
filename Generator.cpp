#include "Template.h"
#include "Generator.h"

#include <iostream>
#include <cstdlib>


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
	_test_file << _template->getHeader() << endl;
}


void Generator::_generateFunctionsBody()
{
	for(int i = 0; i < _func_num; ++i)
		_test_file << _template->getFunctionByNum(i) << endl;
}


void Generator::_generateMain()
{
	_test_file << _template->getMain() << endl;
}


Generator::~Generator()
{
	// Close generated file.
	_test_file.close();
	delete _template;

	// cout << "Destroy Generator." << endl; 
}