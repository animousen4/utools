#pragma once

#include <list>
#include <vector>
#include <string>
using namespace std;
class StringHelper
{	
	public:
		static vector<string> separateByDelimiter(string str, vector<char> delimiter);
		static vector<int> getOnlyNumbers(vector<string> strList);
		static bool isNumber(string str);
};

