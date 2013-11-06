

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <string>
#include <vector>

class Template
{
private: 
	std::vector<int> _funcNums;
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