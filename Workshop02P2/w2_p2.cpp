#define _CRT_SECURE_NO_WARNINGS
//#include <crtdbg.h>
#include <iostream>
#include "hotel.h"
#include "hotel.h" // intentional


int cout = 0; // won't compile if headers don't follow convention regarding namespaces

const int ERROR_TEST_FAILED = 1;

int main()
{
	// a bunch of people
	seneca::Guest travellers[15];
	seneca::setGuest(travellers[ 0], "Derek", "Stevens");
	seneca::setGuest(travellers[ 1], "Brooke", "Rogers");
	seneca::setGuest(travellers[ 2], "Vivian", "Lloyd");
	seneca::setGuest(travellers[ 3], "Arianna", "Montgomery");
	seneca::setGuest(travellers[ 4], "Edwin", "Montgomery");
	seneca::setGuest(travellers[ 5], "Preston", "Murray");
	seneca::setGuest(travellers[ 6], "Jessica", "Alexander");
	seneca::setGuest(travellers[ 7], "Daniel", "Jones");
	seneca::setGuest(travellers[ 8], "April", "Perry");
	seneca::setGuest(travellers[ 9], "James", "Payne");
	seneca::setGuest(travellers[10], "Chelsea", "Murphy");
	seneca::setGuest(travellers[11], "Owen", "Clark");
	seneca::setGuest(travellers[12], "Myra", "Perry");
	seneca::setGuest(travellers[13], "Ellia", "Craig");
	seneca::setGuest(travellers[14], "Chelsea", "Armstrong");

	// create a `Hotel` object
	seneca::Hotel aHotel;
	// populate the hotel object with data from a file
	seneca::loadData("hotel.csv", aHotel);

	{
		// TEST: Print the Information about an empty hotel
		std::cout << "T1: Empty Hotel\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::display(aHotel);
	}

	{
		// TEST: Search for some rooms
		std::cout << "\n\nT2: Looking for a Room\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::Room* aRoom = seneca::findRoom(aHotel, "B102");
		if (aRoom == nullptr)
			std::cout << "[SUCCESS] Room B102 doesn't exists in the hotel!\n";
		else
		{
			std::cout << "[FAIL] Room B102 doesn't exists in the hotel;\n"
				"       The function `seneca::findRoom` should return null.\n";
			return ERROR_TEST_FAILED;
		}

		aRoom = seneca::findRoom(aHotel, "B1002");
		if (aRoom != nullptr)
		{
			std::cout << "[SUCCESS] Room B1002 was found in the hotel!\n";
			seneca::display(*aRoom);
		}
		else
		{
			std::cout << "[FAIL] Room B1002 exists in the hotel;\n"
				"       The function `seneca::findRoom` should return\n"
				"       the address of a valid object.\n";
			return ERROR_TEST_FAILED;
		}
	}
	
	{
		// TEST: Some Guests Arrive at the Hotel
		std::cout << "\n\nT3: Guests have arrived\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::Room* aRoom = seneca::findRoom(aHotel, "A11");
		seneca::addGuest(*aRoom, travellers[3]);
		seneca::addGuest(*aRoom, travellers[4]);
		seneca::display(aHotel);
	}

	{
		// TEST: Too many guest try to occupy a single room
		std::cout << "\n\nT4: Too Many Guests in a Room\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::Room* aRoom = seneca::findRoom(aHotel, "B1001");
		for (int i = 5; i < 10; ++i)
			seneca::addGuest(*aRoom, travellers[i]);
		seneca::display(aHotel);
	}
	
	{
		// TEST: All travelers are at the hotel
		std::cout << "\n\nT5: All Travellers Have Arrived\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::addGuest(*(seneca::findRoom(aHotel, "A12")), travellers[0]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "B1002")), travellers[1]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "B1002")), travellers[2]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "B1002")), travellers[9]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "B1002")), travellers[10]);

		seneca::addGuest(*(seneca::findRoom(aHotel, "C202")), travellers[11]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "C202")), travellers[12]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "C201")), travellers[13]);
		seneca::addGuest(*(seneca::findRoom(aHotel, "C201")), travellers[14]);

		seneca::display(aHotel);
	}

	{
		// TEST: Show a occupied room
		std::cout << "\n\nT6: Show Room C201\n";
		std::cout << "==========:==========:==========:==========:==========\n";

		seneca::Room* aRoom = seneca::findRoom(aHotel, "C201");
		seneca::display(*aRoom);
		std::cout << '\n';
	}

	deallocate(aHotel);
	//_CrtDumpMemoryLeaks();
	return cout;
}
