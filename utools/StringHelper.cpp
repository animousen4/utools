#include "StringHelper.h"


list<string> StringHelper::separateByDelimiter(string str, list<char> delimiter)
{	
	list<string> words;
	string currentWord;
	bool delimiterInduck;
	for (char strC : str) {
		delimiterInduck = false;
		for (char delC : delimiter) {
			if (strC == delC) {
				if (!currentWord.empty()) {
					words.push_back(currentWord);
					currentWord = "";
				}
				delimiterInduck = true;
				break;
			} 
		}
		if (!delimiterInduck)
			currentWord += strC;
	}

	if (!currentWord.empty())
		words.push_back(currentWord);


	return words;
}

list<int> StringHelper::getOnlyNumbers(list<string> strList)
{
	list<int> numList;
	for (string str : strList)
		if (isNumber(str))
			numList.push_back(stoi(str));

	return numList;
}

bool StringHelper::isNumber(string str)
{
	for (char c : str)
		if (!isdigit(c))
			return false;

	return true;
}
