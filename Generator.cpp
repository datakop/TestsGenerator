#include "Template.h"
#include "Generator.h"

#include <iostream>
#include <cstdlib>


using namespace std;

/*
			Constructor and Destructor
___________________________________________________
*/

Generator::Generator(int func_num, const char* file_name)
{
	_func_num = func_num;
	_test_file.open(file_name);

	_template = new Template();
}



/*
			Public Methods
___________________________________________________
*/


/*
			Private Methods
___________________________________________________
*/

void Generator::generate(int i)
{
	_generateHeader();
	_generateFunctionsBody();
	_generateMain(i);
}


void Generator::_generateHeader()
{
	_test_file << _template->getHeader() << endl;
}


void Generator::_generateFunctionsBody()
{
	for(int i = 1; i < _func_num; ++i)
		_test_file << _template->getFunctionByNum(i) << endl;
}



void Generator::_mainHead()
{
	_test_file << _template->getMainHead() << endl;
}

void Generator::_mainBody(int count)
{	
	for (int i = 0; i < count; ++i)
	{
		_test_file << _template->getMainBody(1) << endl;
	}
}

// TODO(kopbob): fix it, Generator can't do what!
void Generator::_mainFooter()
{
	_test_file << "return 0;\n}" << endl;
}


void Generator::_generateMain(int i)
{
	_mainHead();
	_mainBody(i);
	_mainFooter();
	// _test_file << _template->getMain(i) << endl;
}


Generator::~Generator()
{
	// Close generated file.
	_test_file.close();
	delete _template;

	// cout << "Destroy Generator." << endl; 
}