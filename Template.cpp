
#include "Template.h"

#include <iostream>
#include <ctemplate/template.h>  
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

namespace statment {
	enum STMT { IF, FOR, CALL };
}


Template::Template()
{
	srand (time(NULL));
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

string Template::getMainHead()
{
	ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./templates/main/head.tpl",
														ctemplate::DO_NOT_STRIP);
	
	string output;
	tpl->Expand(&output, NULL);

	return output;
}

// string Template::getMainBody(int i)
// {
// 	return to_string(i);
// }


// TODO(kopbob): translate bool to string for COUNT param
string f_IF(bool boolSTMT, string stmt1 ,string stmt2)
{
	ctemplate::TemplateDictionary dict("for");
	dict.SetValue("BOOL", "1");
	dict.SetValue("STMT1", stmt1);
	dict.SetValue("STMT2", stmt2);
	ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./templates/stmts/if.tpl",
														ctemplate::DO_NOT_STRIP);
	
	string output;
	tpl->Expand(&output, &dict);

	return output;
}


string f_FOR(int count, string stmt)
{
	ctemplate::TemplateDictionary dict("for");
	dict.SetValue("COUNT", to_string(count));
	dict.SetValue("STMT", stmt);

	ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./templates/stmts/for.tpl",
														ctemplate::DO_NOT_STRIP);
	
	string output;
	tpl->Expand(&output, &dict);

	return output;
}


string f_CALL(int num)
{
	ctemplate::TemplateDictionary dict("call");
	dict.SetValue("NUM", to_string(num));

	ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./templates/stmts/call.tpl",
														ctemplate::DO_NOT_STRIP);
	
	string output;
	tpl->Expand(&output, &dict);

	return output;
}


string getStmt()
{
	statment::STMT c = static_cast<statment::STMT>(rand() % 3);
	switch (c) 
	{
		case statment::IF:
		{
			return f_IF(true, getStmt(), getStmt());
		}
		case statment::FOR:
		{
			return f_FOR(rand()%10 + 1, getStmt());
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

string generateMain(int i)
{
	if (i) return getStmt() + generateMain(--i);
	else return string("");
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
	cout << generateMain(1) << endl;

	return output;
}

string Template::getMainBody(int i)
{
	string output;
	ctemplate::TemplateDictionary dict("BODY");
	dict.SetValue("BODY", generateMain(i));

	// Compile template to output
	ctemplate::ExpandTemplate("./templates/main/body.tpl",
			ctemplate::DO_NOT_STRIP,
			&dict,
			&output);
	// cout << generateMain(1) << endl;

	return output;
}


Template::~Template()
{
	// cout << "Destroy Template." << endl;
}


