#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

bool checkTwoStr(const char* name);
bool checkNameFormat(char* name);

int main() {

	bool checktwo = checkTwoStr("Cody MacDonald");
	std::cout << checktwo;

	checkNameFormat("Cody A.MacDonald");
	
}

bool checkTwoStr(const char* name) {
	int index = 0;
	int wordcount = 0;

	while (index <= strlen(name))
	{
		if (name[index] == ' ' || name[index] == '\0')
		{
			++wordcount;
		}
		++index;
	}

	return (wordcount == 2) ? true : false;
}


bool checkNameFormat(char* name) {
	char temp[50] = strtok(name, " ");
	std::cout << *temp;

	return true;
}