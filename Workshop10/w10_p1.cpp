// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// April 03, 2024
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "Student.h"
#include "MatchPair.h"

int cout = 0; // prevents compilation if headers don't follow convention

int main()
{
	const int size1 = 9;
	const int size2 = 8;
	int size3;
	int x[] = { 288, 1001, 322, 554, 3, 66, 758, 2022, 70 };
	double y[] = { 1.999, 26.96, 3.00, 103.72, 59.9, 88.8, 37.95, 322.00 };
	seneca::Book bks[] = { seneca::Book("C Programming Langauge",   288,  26.96,"BSABSDCPACPP", 4),
	                       seneca::Book("Learn Python Programming", 554,  59.99,"BTMDSADAD",    3),
	                       seneca::Book("Pat Recog and Mach Learn", 758, 103.72,"DSABSA",       2),
	                       seneca::Book("Mach Learn in Business",   287,  37.95,"BTMBSD",       2)
	                     };

	float marks_A[]{ 56.6f, 62.2f, 71.2f };
	float marks_B[]{ 59.9f, 80.1f };
	float marks_C[]{ 88.8f };
	float marks_D[]{ 80.1f, 70.2f,66.6f };
	float marks_E[]{ 58.8f, 64.4f };
	float marks_F[]{ 81.1f, 76.6f, 72.2f };
	float marks_G[]{ 50.0f, 61.1f, 70.9f, 81.1f };

	seneca::Student stds[] = { seneca::Student(1001,"Beans Yanson", "BSD", marks_A, 3),
	                           seneca::Student(1005,"Archie Mollen","BSA", marks_B, 2),
	                           seneca::Student(1026,"Mugsy Brown",  "CPA", marks_C, 1),
	                           seneca::Student(2022,"Sally Sparrow","CPP", marks_D, 3),
	                           seneca::Student(2033,"Maulin Codi",  "BTM", marks_E, 2),
	                           seneca::Student(1055,"John Bolton",  "DSA", marks_F, 3),
	                           seneca::Student(2130,"Joe Jackson",  "DAD", marks_G, 4)
	                         };
	
	std::cout << "========================================================================\n";
	std::cout << "|| T1. Match tester for int and double arrays (double matched to int) ||\n";
	std::cout << "+------------+---------------+------------------------------------------\n";
	std::cout << "| int value  | double value  |\n";
	std::cout << "+ ---------- + ------------- +\n";


	/// TODO-1a: call `matches` function for arrays `x` and `y`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret1`
	seneca::Pair<int,double>* ret1 = seneca::matches(x, y, size1, size2, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "|    " << std::setw(6) << ret1[i].first << " <-> " << std::setw(6)
		          << std::fixed << std::setprecision(2) << ret1[i].second << "       |\n";
	}
	

	/// TODO-1b: call `releaseMem` function to release dynamic array `ret1`
	seneca::releaseMem(ret1);


	std::cout << "+------------+---------------+\n";
	std::cout << std::endl;
	std::cout << "===============================================================================\n";
	std::cout << "|| T2. Match tester for Book and int arrays (int matched to number of pages) ||\n";
	std::cout << "+--------------------------------------------------------------+------------+\n";
	std::cout << "|                            Book                              |  int value |\n";
	std::cout << "+ ------------------------------------------------------------ + ---------- +\n";


	/// TODO-2a: call `matches` function for arrays `bks` and `x`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret2`
	seneca::Pair<seneca::Book, int>* ret2 = seneca::matches(bks, x, 4, 8, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "| " << std::setw(70) << ret2[i].first << " <-> " 
		          << ret2[i].second << "       |\n";
	}
	

	/// TODO-2b: call `releaseMem` function to release dynamic array `ret2`
	seneca::releaseMem(ret2);


	std::cout << "+--------------------------------------------------------------+------------+\n";
	std::cout << std::endl;
	std::cout << "================================================================================\n";
	std::cout << "|| T3. Match tester for Book and double arrays (double matched to book price) ||\n";
	std::cout << "+--------------------------------------------------------------+---------------+\n";
	std::cout << "|                             Book                             |  double value |\n";
	std::cout << "+ ------------------------------------------------------------ + ------------- +\n";


	/// TODO-3a: call `matches` function for arrays `bks` and `y`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret3`
	seneca::Pair<seneca::Book,double>* ret3 = seneca::matches(bks, y, 4, 8, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "| " << ret3[i].first << " <-> " << std::setw(6) << std::fixed
		          << std::setprecision(2) << ret3[i].second << "       |" << std::endl;
	}


	/// TODO-3b: call `releaseMem` function to release dynamic array `ret3`
	seneca::releaseMem(ret3);


	std::cout << "+--------------------------------------------------------------+---------------+\n";
	std::cout << std::endl;
	std::cout << "==============================================================================\n";
	std::cout << "|| T4. Match tester for Student and int arrays (int matched to student id)  ||\n";
	std::cout << "+--------------------------------------------------+---------------+----------\n";
	std::cout << "|                     Student                      |  int value    |\n";
	std::cout << "+ ------------------------------------------------ + ------------- +\n";


	/// TODO-4a: call `matches` function for arrays `stds` and `x`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret4`
	seneca::Pair<seneca::Student, int>* ret4 = seneca::matches(stds, x, 7, 9, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "| " << ret4[i].first << " <-> " << ret4[i].second << "         |" << std::endl;
	}


	/// TODO-4b: call `releaseMem` function to release dynamic array `ret4`
	seneca::releaseMem(ret4);


	std::cout << "+--------------------------------------------------+---------------+\n";
	std::cout << std::endl;
	std::cout << "=======================================================================================\n";
	std::cout << "|| T5. Match tester for Student and double arrays (double matched to average marks)  ||\n";
	std::cout << "+--------------------------------------------------+---------------+-------------------\n";
	std::cout << "|                      Student                     |  Double value |\n";
	std::cout << "+ ------------------------------------------------ + ------------- +\n";


	/// TODO-5a: call `matches` function for arrays `stds` and `y`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret5`
	seneca::Pair<seneca::Student,double>* ret5 = seneca::matches(stds, y, 7, 8, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "| " << ret5[i].first << " <-> " << ret5[i].second << "        |" << std::endl;
	}


	/// TODO-5b: call `releaseMem` function to release dynamic array `ret5`
	seneca::releaseMem(ret5);


	std::cout << "+--------------------------------------------------+---------------+\n";
	std::cout << std::endl;
	std::cout << "===============================================================================================================\n";
	std::cout << "|| T6. Match tester for Student and Book arrays (student program matched to programs in which book is used)  ||\n";
	std::cout << "+--------------------------------------------------+-----------------------------------------";
	std::cout << "---------------------+\n";
	std::cout << "|                       Student                    |  ";
	std::cout << "                         Book                               |\n";
	std::cout << "+ ------------------------------------------------ + ";
	std::cout << "------------------------------------------------------------ +\n";


	/// TODO-6a: call `matches` function for arrays `stds` and `bks`, pass `size3` as 5th argument;
	/// copy returned address to a pointer called `ret6`
	seneca::Pair<seneca::Student, seneca::Book>* ret6 = seneca::matches(stds, bks, 7, 4, size3);


	for (int i = 0; i < size3; i++)
	{
		std::cout << "| " << ret6[i].first << " <-> " << ret6[i].second << " |" << std::endl;
	}


	/// TODO-6b: call `releaseMem` function to release dynamic array `ret6`
	seneca::releaseMem(ret6);


	std::cout << "+--------------------------------------------------+-----------------------------------------";
	std::cout << "---------------------+\n";

	return cout;
}
