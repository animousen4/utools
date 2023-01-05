#pragma once

#include <list>
#include <string>
using namespace std;
class StringHelper
{	
	public:
		static list<string> separateByDelimiter(string str, list<char> delimiter);
		static list<int> getOnlyNumbers(list<string> strList);
		static bool isNumber(string str);
};

