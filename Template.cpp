
#include "Template.h"

#include <iostream>
// #include <ctemplate/template.h>  
#include <algorithm>
#include <random>
#include <ctime>

#define RECURSION_DEEP 20

using namespace std;

namespace statment {
	enum STMT { IF, FOR, CALL };
}

string _fillTemplate(ctemplate::TemplateDictionary &dict, string tpl_name)
{
	string output;
	ctemplate::ExpandTemplate(string("./templates/") + tpl_name,
			ctemplate::DO_NOT_STRIP,
			&dict,
			&output);
	return output;
}

/*
			Constructor and Destructor
___________________________________________________
*/

Template::Template()
{
	srand(time(NULL)); 
}


Template::~Template()
{
}



/*
			Public Methods
___________________________________________________
*/

string Template::getHeader()
{
	ctemplate::TemplateDictionary dict("empty");
	return _fillTemplate(dict, "header.tpl");
}

string Template::getFunctionByNum(int num)
{
	_funcNums.push_back(num);

	ctemplate::TemplateDictionary dict("func");
	dict["NUM"] = num;

	return _fillTemplate(dict, "function.tpl");
}

string Template::getMainHead()
{
	ctemplate::TemplateDictionary dict("empty");
	return _fillTemplate(dict, "main/head.tpl");
}

// TODO(kopbob): fix i vaiable
// Get pice of main body
string Template::getMainBody(int i)
{
	string output;
	ctemplate::TemplateDictionary dict("BODY");
	dict.SetValue("BODY", _generateMain(i));	
	return _fillTemplate(dict, "main/body.tpl");
}

// Old version
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

	return _fillTemplate(dict, "main.tpl");
}



/*
			Private Methods
___________________________________________________
*/


// TODO(kopbob): translate bool to string for COUNT param
string f_IF(bool boolSTMT, string stmt1 ,string stmt2)
{
	ctemplate::TemplateDictionary dict("for");
	dict.SetValue("BOOL", "1");
	dict.SetValue("STMT1", stmt1);
	dict.SetValue("STMT2", stmt2);
	
	return _fillTemplate(dict, "stmts/if.tpl");
}


string f_FOR(int count, string stmt)
{
	ctemplate::TemplateDictionary dict("for");
	dict.SetValue("COUNT", to_string(count));
	dict.SetValue("STMT", stmt);

	return _fillTemplate(dict, "stmts/for.tpl");
}


string f_CALL(int num)
{
	ctemplate::TemplateDictionary dict("call");
	dict.SetValue("NUM", to_string(num));

	return _fillTemplate(dict, "stmts/call.tpl");
}

// TODO(kopbo): set deep limitation
string Template::_getStmt(int deep)
{
	if (deep <= 0) return "";
	deep--;
	statment::STMT c = static_cast<statment::STMT>(rand() % 3);
	switch (c) 
	{
		case statment::IF:
		{
			return f_IF(true, _getStmt(deep), _getStmt(deep));
		}
		case statment::FOR:
		{
			return f_FOR(rand()%10 + 1, _getStmt(deep));
		}
		case statment::CALL:
		{
			return f_CALL(rand()%100 + 1);
		}
		default:
		{
			cout << "ERROR" << endl;
			return "";
		}
	}
}

string Template::_generateMain(int i)
{
	if (i) return _getStmt(RECURSION_DEEP) + _generateMain(--i);
	else return string("");
}







