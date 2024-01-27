#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "hotel.h"
#include "file.h"

using namespace std;
namespace seneca {
	
	void setGuest(Guest& theGuest, const char* fName, const char* lName)
	{
		strcpy(theGuest.m_firstName, fName);
		strcpy(theGuest.m_lastName, lName);
	}

	bool loadData(const char* filename, Hotel& theHotel)
	{
		bool exitFlag = false;
		if (theHotel.m_cntRooms)
		{
			//deallocateMemory();
		}
		else
		{
			bool status = openFile(filename);
			if (status)
			{
				theHotel.m_cntRooms = getRecordsCount();
				theHotel.m_rooms = new Room[theHotel.m_cntRooms];
				for (int i = 0; i < theHotel.m_cntRooms; i++)
				{
					loadData(theHotel.m_rooms[i]);
				}
				closeFile();
				exitFlag = true;
			}
		}
		return exitFlag;
	}

	bool loadData(Room& theRoom)
	{
		bool exitFlag = false;
		theRoom.m_roomNumber = read();
		bool maxCntGuestFlag = read(theRoom.m_maxCntGuests, '\n');
		if (theRoom.m_roomNumber != NULL && maxCntGuestFlag)
		{
			exitFlag = true;
		}
		return exitFlag;
	}
	
	void display(const Hotel& theHotel)
	{
		int RoomTypeCounter = 1;
		cout << "Standard Rooms:" << endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'A')
			{
				cout << RoomTypeCounter << ". " << theHotel.m_rooms[i].m_roomNumber;
				cout << " (" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
				RoomTypeCounter++;
			}
		}
		RoomTypeCounter = 1;
		cout << "Family Rooms:" << endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'B')
			{
				cout << RoomTypeCounter << ". " << theHotel.m_rooms[i].m_roomNumber;
				cout << " (" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
				RoomTypeCounter++;
			}
		}
		RoomTypeCounter = 1;
		cout << "Suites:" << endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'C')
			{
				cout << RoomTypeCounter << ". " << theHotel.m_rooms[i].m_roomNumber << 
					" (" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
				RoomTypeCounter++;
			}
		}
	}

	void display(Room theRoom)
	{
		if (theRoom.m_cntGuests > 0)
		{
			cout << theRoom.m_roomNumber << " (" << theRoom.m_cntGuests << "/" << theRoom.m_maxCntGuests << "): " << theRoom.m_guests[0].m_firstName << ' ' << theRoom.m_guests[0].m_lastName;
			for (int i = 1; i < theRoom.m_cntGuests; i++)
			{
				cout << ", " << theRoom.m_guests[i].m_firstName << " " << theRoom.m_guests[i].m_lastName;
			}
			cout << endl;
		}
		else
		{
			cout << theRoom.m_roomNumber << " (" << theRoom.m_cntGuests << "/" << theRoom.m_maxCntGuests << ")" << endl;
		}
	}

	/* TODO: add the prototype of the `addGuest` function that receives as a parameters
	*         a reference to an object of type `Room` and an unmodifiable reference
	*         to an object of type `Guest`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* addGuest()
	* - resize the array of guests currently staying in the room, but only if there
	*     enough capacity to accommodate the new guest.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	void addGuest(Room& theRoom, Guest theGuest)
	{
		if (theRoom.m_cntGuests < theRoom.m_maxCntGuests)
		{
			if (theRoom.m_cntGuests = 0)
			{
				theRoom.m_guests = new Guest[theRoom.m_cntGuests + 1];
				theRoom.m_guests[theRoom.m_cntGuests + 1] = theGuest;
			}
			else
			{
				Guest* Temp = new Guest[theRoom.m_cntGuests];
				for (int i = 0; i < theRoom.m_cntGuests; i++)
				{
					Temp[i] = theRoom.m_guests[i];
				}
				delete[] theRoom.m_guests;
				theRoom.m_guests = new Guest[theRoom.m_cntGuests + 1];
				for (int i = 0; i < theRoom.m_cntGuests; i++)
				{
					 theRoom.m_guests[i] = Temp[i];
				}
				theRoom.m_guests[theRoom.m_cntGuests + 1] = theGuest;
				delete [] Temp;
			}
		}
	}

	Room* findRoom(Hotel theHotel, const char* roomNumber)
	{
		Room* addr = nullptr;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (string(theHotel.m_rooms[i].m_roomNumber) == roomNumber)
			{
				addr = &theHotel.m_rooms[i];
			}
		}
		return addr;
	}

	/// <summary>
	/// Deallocates all dynamic memory used by a `Hotel` object.
	/// </summary>
	/// <param name="theHotel">the object whose memory must be deallocated.</param>
	/* TODO: add the prototype of the `deallocate` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* deallocate()
	* - deallocate all the dynamic memory used by the hotel:
	*   - the room number and the array of guests (for each room)
	*   - the array of rooms
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
}