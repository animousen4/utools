
#include "utools.h";
#include <iostream>
using namespace std;
int main() {

	CustomList<int> customList;
	
	customList.push_back(1);

	cout << customList[0];
}