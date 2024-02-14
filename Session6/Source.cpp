#include <iostream>
#include <fstream>

int main()
{

	std::ofstream file;
	file.open("data.txt");
	if (file.is_open())
	{
		file << "Hello world from C++!\n" << "Bye.";
	}
	else
	{
		std::cout << "Error: File could not be opened" << std::endl;
	}

}