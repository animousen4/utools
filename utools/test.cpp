
#include "utools.h";
#include <iostream>
using namespace std;
int main() {

	auto res = StringHelper::separateByDelimiter("barack obama", { ' ' });
	cout << res[1];

	
}