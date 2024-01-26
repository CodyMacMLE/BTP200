#ifndef W2_HOTEL_H
#define W2_HOTEL_H

namespace seneca {
/// <summary>
/// A structure that contains information about a single person that stays
///   at a hotel
/// </summary>
struct Guest
{
		/// <summary>
		/// The first name of the person.
		///   The name must not exceed 100 characters.
		/// </summary>
		char m_firstName[101]{};
		/// <summary>
		/// The last name of the person.
		///   The name must not exceed 100 characters.
		/// </summary>
		char m_lastName[101]{};
	};

	/// <summary>
	/// A structure that contains information about a single room that
	///   guests can rent.
	/// </summary>
	struct Room
	{
		/// <summary>
		/// The room number. The first letter of the room number specifies
		///   in which building the room is located:
		///   - Building 'A': Standard Rooms (for solo travelers or couples)
		///   - Building 'B': Family Rooms (rooms for families with kids)
		///   - Building 'C': Suites (apartment-style with at least 2 bedrooms)
		/// 
		/// This attribute stores the address of a dynamically-allocated array
		///   of characters.
		/// </summary>
		char* m_roomNumber = nullptr;
		/// <summary>
		/// The MAXIMUM number of guests that can stay in the room at a given
		///   moment.  This is the capacity of the room.  Large families/parties
		///   should book large rooms.
		/// </summary>
		int m_maxCntGuests = 0;
		/// <summary>
		/// The number of guests that currently stay in the room.
		/// 
		/// This number cannot exceed `m_maxCntGuests`.
		/// </summary>
		int m_cntGuests = 0;
		/// <summary>
		/// A collection of `Guest` objects of size `m_cntGuests`.
		/// 
		/// This attributes stores the address of a dynamically-allocated
		///   array of objects of type `Guest`.
		/// </summary>
		Guest* m_guests = nullptr;
	};

	/// <summary>
	/// A structure that contains information about a single hotel.
	/// </summary>
	struct Hotel
	{
		/// <summary>
		/// A collection of rooms of some undetermined size.
		/// 
		/// This attribute stores the address of a dynamically-allocated
		///   array of objects of type `Room`.
		/// </summary>
		Room* m_rooms = nullptr;
		/// <summary>
		/// The number of rooms in the collection.
		/// </summary>
		int m_cntRooms = 0;
	};

	/// <summary>
	/// Sets the first name and last name of a guest.
	/// </summary>
	/// <param name="theGuest">the guest whose name must be set.</param>
	/// <param name="fName">the first name of the guest</param>
	/// <param name="lName">the last name of the guest</param>
	void setGuest(Guest& theGuest, const char* fName, const char* lName);


	/// <summary>
	/// Load all information about the rooms found in a file and store it in
	///   the `Hotel` object.
	/// </summary>
	/// <param name="fileName">the name of the file containing data.</param>
	/// <param name="theHotel">the object that must be populated with data
	///   extracted from the file.</param>
	bool loadData(const char* filename, Hotel theHotel);

	/// <summary>
	/// Load from a file the information about a single room.
	/// </summary>
	/// <param name="theRoom">the object where to put data loaded from the file</param>
	bool loadData(Room theRoom);

	/// <summary>
	/// Print to screen the details of the hotel.
	/// </summary>
	/// <param name="theHotel">the hotel whose details are to be printed.</param>
	void display(const Hotel& theHotel);
}
#endif