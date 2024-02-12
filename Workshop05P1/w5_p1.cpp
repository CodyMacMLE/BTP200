#include <iostream>
#include "bankAccount.h"
#include "bankAccount.h"    // intentional

int cout = 0; // prevents compilation if headers don't follow convention

int main()
{
	seneca::BankAccount accounts[]{
		seneca::BankAccount("Joe Williams", true),     // OK
		seneca::BankAccount("Cindy Kofler", false),    // OK
		seneca::BankAccount(),                         // NOT OK -> Empty State
		seneca::BankAccount("Rohan Kumaar", true),     // OK
		seneca::BankAccount(nullptr, true),            // NOT OK -> Bad Name
		seneca::BankAccount("Raya Chandok", false),    // OK
		seneca::BankAccount("Silvia Smith"),           // OK
		seneca::BankAccount("", true),                 // NOT OK -> Bad Name
	};

	{
		// TEST
		std::cout << "T1: Testing Account Setup\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		for (auto i = 0; i < 8; ++i)
		{
			// will not compile if the display function is not a query
			const seneca::BankAccount& theAccount = accounts[i];
			theAccount.display();
		}
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}
/*
	{
		// TEST
		std::cout << "T2: Credit and Debit the Accounts\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		(accounts[0] += 100.5) += 10.45; // Funds in account: 110.95
		(accounts[1] += 123.45) -= 3.81; // Funds in account: 119.64
		accounts[2] -= 0;                // Nothing happens -> account not open
		(accounts[3] -= 20) += 385.33;   // Funds in account: 365.33
		accounts[4] -= 7.77;             // Nothing happens -> account not open
		(accounts[5] -= 5.55) -= 4.45;   // Funds in account: -10.00
		accounts[6] += 1000;             // Funds in account: 1000.00
		accounts[7] += 1000;             // Nothing happens -> account not open
		for (auto i = 0; i < 8; ++i)
			accounts[i].display();
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T3: Casting-to-bool operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		for (auto i = 0; i < 8; ++i)
		{
			// will not compile if the conversion-to-bool operator is not a query
			const seneca::BankAccount& theAccount = accounts[i];
			std::cout << "#" << i + 1 << ". Is account open? " << (theAccount ? "yes" : "no") << std::endl;
		}
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T4: The other casting operators\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		for (auto i = 0; i < 8; ++i)
		{
			// the accounts that are not open, should print Not-a-Number (nan) for funds
			//   and -1 for number of transactions

			// will not compile if the conversion-to-bool operator is not a query
			const seneca::BankAccount& theAccount = accounts[i];
			std::cout << "#" << i + 1 << " "
				<< "[" << (const char*)theAccount << "]"         // holder's name
				<< "[" << (double)theAccount << "]"              // funds
				<< "[" << (int)theAccount << "]"                 // number of transactions
				<< std::endl;
		}
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T5: Add Interest to all accounts\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		for (auto i = 0; i < 8; ++i)
		{
			(accounts[i]++).display(); // prints the value before interest (postfix++)
			accounts[i].display();     // prints the value after interest
			(++accounts[i]).display(); // add interest again; prints the value after interest (prefix++)
		}
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T6: Test comparison operators\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will not compile if the comparison operators are not queries
		const seneca::BankAccount& theAccount = accounts[1];
		theAccount.display();
		std::cout << "Cindy has more than $125 in her acc? " << (theAccount > 125.0 ? "yes" : "no") << std::endl;
		std::cout << "Is $125 bigger than Cindy's balance? " << (125.0 > theAccount ? "yes" : "no") << std::endl;
		std::cout << "Cindy has more than $126 in her acc? " << (theAccount > 126.0 ? "yes" : "no") << std::endl;
		std::cout << "Is $126 bigger than Cindy's balance? " << (126.0 > theAccount ? "yes" : "no") << std::endl;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// TEST
		std::cout << "T7: Deposit funds\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will not compile if the operator+ is not query
		const seneca::BankAccount& theAccount = accounts[3];
		theAccount.display();
		seneca::BankAccount secondAcc = (theAccount + 345.12);
		secondAcc.display(); // original object is not modified
		(accounts[2] + 123.5).display(); // empty account; the operations do nothing

		std::cout
			<< "[" << (const char*)theAccount << "]"         // holder's name
			<< "[" << (double)theAccount << "]"              // funds
			<< "[" << (int)theAccount << "]"                 // number of transactions
			<< std::endl;
		std::cout
			<< "[" << (const char*)secondAcc << "]"         // holder's name
			<< "[" << (double)secondAcc << "]"              // funds
			<< "[" << (int)secondAcc << "]"                 // number of transactions
			<< std::endl;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n";
	}
*/
	return cout;
}
