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

	/* TODO: add the prototype of the `loadData` function that receives as parameters
	*         the address of a C-string with the file name containing the data, and
	*         a reference to an object of type `Hotel`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - the file contains information about an undetermined number of rooms that a hotel
	*     has. Each line from the file contains information about a single room in the
	*     format:
	*
	*     `ROOM_NUMBER,ROOM_CAPACITY\n`
	*
	* - the number of rooms and the number of characters for a single ROOM_NUMBER is not
	*     known, and must be determined at runtime; use dynamic memory to store this info
	*     in your program. Allocate *exactly* the amount of memory necessary and not more.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool loadData(const char* filename, Hotel theHotel)
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


	/* TODO: add the prototype of the `loadData` function that receives as a parameter
	*         a reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - load the room number (in a dynamically-allocated string) and the capacity
	*     of the room (as an integer) and store them in the attributes of the parameter.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool loadData(Room theRoom)
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
	
	/* TODO: add the prototype of the `display` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Hotel`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - print the data stored in the object in the following format:
	*     `Standard Rooms:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_A`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_A`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_A`
	*     `...`
	*     `Family Rooms:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_B`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_B`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_B`
	*     `...`
	*     `Suites:\n`
	*     `1. DETAILS_OF_FIRST_ROOM_IN_BUILDING_C`
	*     `2. DETAILS_OF_SECOND_ROOM_IN_BUILDING_C`
	*     `3. DETAILS_OF_THIRD_ROOM_IN_BUILDING_C`
	*     `...`
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	void display(const Hotel& theHotel)
	{
		int RoomTypeCounter = 1;
		cout << "Standard Rooms:" << endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'A')
			{
				cout << RoomTypeCounter << ". " << theHotel.m_rooms[i].m_roomNumber;
				cout << "(" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
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
				cout << "(" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
				RoomTypeCounter++;
			}
		}
		RoomTypeCounter = 1;
		cout << "Suites:" << endl;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == 'C')
			{
				cout << RoomTypeCounter << ". " << theHotel.m_rooms[i].m_roomNumber;
				cout << "(" << theHotel.m_rooms[i].m_cntGuests << "/" << theHotel.m_rooms[i].m_maxCntGuests << ")" << endl;
				RoomTypeCounter++;
			}
		}
	}

	/// <summary>
	/// Print to screen the details of a single room.
	/// </summary>
	/// <param name="theRoom">the room whose details are to be printed.</param>
	/* TODO: add the prototype of the `display` function that receives as a parameter
	*         an unmodifiable reference to an object of type `Room`.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - if the room has guests, print the data stored formatted as:
	*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS): GUEST_1, GUEST_2, ...`
	* - if the room has no guests, print the data stored formatted as:
	*     `ROOM_NUMBER (NUMBER_OF_GUESTS/MAX_NUMBER_OF_GUESTS)`
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	//? ? ?

		/// <summary>
		/// Add a guest to the room ONLY if the room capacity has not been reached.
		///   If the room is already at capacity, this function does nothing.
		/// </summary>
		/// <param name="theRoom">the room where guests will be staying</param>
		/// <param name="theGuest">the gust that wants to stay in the room</param>
		/* TODO: add the prototype of the `addGuest` function that receives as a parameters
		*         a reference to an object of type `Room` and an unmodifiable reference
		*         to an object of type `Guest`.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* addGuest()
		* - resize the array of guests currently staying in the room, but only if there
		*     enough capacity to accommodate the new guest.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		//? ? ?

		/// <summary>
		/// Searches in the hotel for a room with the number specified in the
		///   second parameter.
		/// </summary>
		/// <param name="theHotel">the hotel where to search for a room.</param>
		/// <param name="roomNumber">the room number being searched.</param>
		/// <returns>the address of the `Room` object with the number specified
		///   in the second parameter, or null if no such room exists.</returns>
		/* TODO: add the prototype of the `findRoom` function that receives as a parameters
		*         an unmodifiable reference to an object of type `Hotel` and the
		*         address of a C-string.
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* findRoom()
		* - search in the hotel a room with the specified "Room Number"
		*     (iterate over the collection of rooms).
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		//? ? ?

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
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		//? ? ?
}