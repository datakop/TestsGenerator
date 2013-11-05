
#include "Template.h"

#include <iostream>
#include <ctemplate/template.h>  
#include <algorithm>
#include <random>

using namespace std;


Template::Template()
{

}


string Template::getHeader()
{
	string output;
	ctemplate::ExpandTemplate("./templates/header.tpl",
			ctemplate::DO_NOT_STRIP,
			NULL,
			&output);
	return output;
}


string Template::getFunctionByNum(int num)
{

	_funcNums.push_back(num);

	ctemplate::TemplateDictionary dict("func");
	dict["NUM"] = num;

	string output;
	ctemplate::ExpandTemplate("./templates/function.tpl",
			ctemplate::DO_NOT_STRIP,
			&dict,
			&output);

	return output;
}


string Template::getMain()
{
	string output;
	ctemplate::TemplateDictionary dict("CALLS");

	// Shuffle functions call order 
	shuffle(_funcNums.begin(),
		_funcNums.end(),
		std::default_random_engine(1));

	// Create main template with function call
	for (auto it = std::begin(_funcNums); it!=std::end(_funcNums); ++it)
	{
		ctemplate::TemplateDictionary* sub_dict = dict.AddSectionDictionary("FUNC_CALLS");
		sub_dict->SetValue("FUNC_CALL", to_string(*it));
	}

	// Compile template to output
	ctemplate::ExpandTemplate("./templates/main.tpl",
			ctemplate::DO_NOT_STRIP,
			&dict,
			&output);

	return output;
}


Template::~Template()
{
	// cout << "Destroy Template." << endl;
}


