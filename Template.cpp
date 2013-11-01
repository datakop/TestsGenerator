
#include "Template.h"

#include <iostream>

using namespace std;

Template::Template()
{

}



string Template::getFunctionByNum(int num)
{

	return 
	"int function(int n)\n"
	"{\n"
	"	for (int i = 0; i < 100; ++i)\n"
	"	{\n"
	"		n++;\n"
	"	}\n"
	"\n"
	"	return n;\n"
	"}\n"
	;
}






Template::~Template()
{
	cout << "Destroy Template." << endl;
}