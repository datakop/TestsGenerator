

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <string>
#include <vector>
#include <ctemplate/template.h>  

class Template
{
private: 
	std::vector<int> _funcNums;

	std::string _getStmt(int);
	std::string _generateMain(int);


public:
	Template();
	~Template();

	std::string getHeader();
	std::string getFunctionByNum(int);

	std::string getMain();
	
	std::string getMainHead();
	std::string getMainBody(int);
};



#endif