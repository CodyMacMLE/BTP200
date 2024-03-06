#include <iostream>
#include <fstream>
#include "inbox.h"
#include "inbox.h"          // intentional
#include "email.h"
#include "email.h"          // intentional

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 6th, 2024

int cout = 0; // prevents compilation if headers don't follow convention

/// <summary>
/// Prints to screen the whole content of the file whose name is received
///   as parameter.
/// </summary>
void dumpFileToScreen(const char* filename);

int main()
{
	// Tests for `Email`
	{
		// Test 1
		std::cout << "T1: Testing the load function for `Email`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::ifstream file("emails_monday.csv");
		if (file.is_open())
		{
			while (file)
			{
				seneca::Email someEmail;
				someEmail.load(file);
				std::cout << someEmail;
			}
			file.close();
		}
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		std::ifstream file("emails_monday.csv");
		seneca::Email emails[4];
		emails[0].load(file);
		emails[1].load(file);
		emails[2].load(file);
		file.close();

		// Test 2
		std::cout << "T2: Testing copy constructor for `Email`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will not compile if prototype for `operator<<` is missing `const`
		const seneca::Email copy(emails[0]);
		std::cout << emails[0] << copy;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 3
		std::cout << "T3: Testing copy assignment for `Email`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << emails[0] << emails[1];
		emails[1] = emails[0];
		std::cout << emails[0] << emails[1];
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 4
		std::cout << "T4: Testing for self-assignment.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will not compile if prototype for `operator=` is missing `const`
		// will crash later if self assignment is not correctly checked
		const seneca::Email& same = emails[0];
		std::cout << emails[0] << same;
		emails[0] = same;
		std::cout << emails[0] << same;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 5
		std::cout << "T5: Testing how empty objects are handled.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << emails[1]
		          << "Should be empty A [" << emails[3] << "]\n";
		// copy empty object into a non-empty one
		emails[1] = emails[3];
		std::cout << "Should be empty B [" << emails[1] << "]\n"
		          << "Should be empty C [" << emails[3] << "]\n";
		// copy non-empty object into an empty one
		emails[3] = emails[2];
		std::cout << emails[3] << emails[2];
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	// Tests for `Inbox`
	{
		// Test 6
		std::cout << "T6: Testing the load function for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Inbox inbox;
		inbox.load("emails_monday.csv");
		std::cout << inbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 7
		std::cout << "T7: Load more emails.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		inbox.load("emails_misc.csv");
		std::cout << inbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// Test 8
		std::cout << "T8: Copy constructor for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Inbox inbox;
		inbox.load("emails_misc.csv");
		const seneca::Inbox outbox(inbox);
		std::cout << inbox << '\n' << outbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// Test 9
		std::cout << "T9: Copy assignment for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Inbox inbox, outbox;
		inbox.load("emails_misc.csv");
		outbox.load("emails_monday.csv");
		outbox = inbox;
		std::cout << inbox << '\n' << outbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		std::ifstream file("emails_monday.csv");
		seneca::Email emails[4];
		emails[0].load(file);
		emails[1].load(file);
		emails[2].load(file);
		file.close();

		// Test 10
		std::cout << "T10: Testing operator+= for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Inbox inbox;
		(inbox += emails[0]) += emails[1];
		std::cout << inbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 11
		std::cout << "T11: Testing operator+ for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will not compile if prototypes are missing `const`
		seneca::Inbox outbox;
		const seneca::Inbox& refInbox = inbox;
		outbox = refInbox + emails[2];
		std::cout << refInbox << '\n' << outbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 12
		std::cout << "T12: Testing for self-assignment for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		// will crash later if self assignment is not correctly checked
		inbox = refInbox;
		std::cout << inbox << '\n' << refInbox;
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}

	{
		// Test 13
		std::cout << "T13: Testing the save function for `Inbox`.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		seneca::Inbox inbox;
		inbox.load("emails_misc.csv");
		inbox.save("emails_important.txt");
		dumpFileToScreen("emails_important.txt");
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";

		// Test 14
		std::cout << "T14: Testing that operator<< uses the param for output.\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::ofstream file("emails_backup.txt");
		file << inbox;
		file.close();
		dumpFileToScreen("emails_backup.txt");
		std::cout << "~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~:~~~~~~~~~~\n\n";
	}


	return cout;
}

void dumpFileToScreen(const char* filename)
{
	std::ifstream file(filename);
	char ch{};
	while (file.get(ch))
		std::cout << ch;
	file.close();
}
