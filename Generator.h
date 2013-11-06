

#ifndef _GENERATOR_H
#define _GENERATOR_H

#include <fstream>

class Template;
class Generator
{
private:
	int _func_num; // Number of random functions
	std::ofstream _test_file;

	Template *_template;

	void _generateHeader();
	void _generateFunctionsBody();
	void _generateMain(int);

	void _mainHead();
	void _mainBody(int);
	void _mainFooter();

public:
	Generator(int,const char*);
	~Generator();

	// Generate test file
	void generate(int);
};



#endif