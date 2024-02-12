#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H
#include <iostream>
#include "guitarString.h"

namespace seneca {

	class Guitar {
		/// <summary>
		/// A statically allocated string that stores th model of the guitar
		/// </summary>
		char m_model[65];

		/// <summary>
		/// A dynamically allocated array that stores an array of GuitarString Obj
		/// </summary>
		GuitarString* m_strings;

		/// <summary>
		/// Stores the number of GuitarString Obj in the array
		/// </summary>
		int m_cntStrings;

	public:

		/// <summary>
		/// A constructor that initializes the object with a model name and default otherwise
		/// </summary>
		/// <param name="model">: a const string of the model name</param>
		Guitar(const char* model = "Stratocaster");

		/// <summary>
		///  A constructor that initializes the object with all custom parameters, default otherwise
		/// </summary>
		/// <param name="strings">: The type of strings of type GuitarStrings</param>
		/// <param name="cntStrings">: an int of the number of string objects</param>
		/// <param name="model">: a const string of the model name</param>
		Guitar(const GuitarString* strings, int cntStrings, const char* model);


		/// <summary>
		/// The destructor that includes the deallocation of the dynamic GuitarString array.
		/// </summary>
		~Guitar();

		/// <summary>
		/// a modifier that removes all the strings from the current obj, and replaces it with those recieved as a parameter
		/// </summary>
		/// <param name="strings">: The type of strings of type GuitarStrings</param>
		/// <param name="cntStrings">: an int of the number of string objects</param>
		/// <returns>: a reference to object of type Guitar</returns>
		Guitar& reString(const GuitarString* strings, int cntStrings);

		/// <summary>
		/// a modifier that changes a single string with the one recieved as parameter
		/// </summary>
		/// <param name="">: a reference to an unmodifiable object of type GuitarString</param>
		/// <param name="idx">: the index of the GuitarString object that must be replaced</param>
		/// <returns>a reference to an object of Guitar</returns>
		Guitar& reString(const GuitarString& aString, int idx);
		
		/// <summary>
		/// a modifier that appends a single string with the one recieved as parameter
		/// </summary>
		/// <param name="aString">: a reference to an unmodifiable object of type GuitarString</param>
		/// <returns>a reference to an object of Guitar</returns>
		Guitar& appendString(const GuitarString& aString);

		/// <summary>
		/// a modifier that removes all the strings from the current obj
		/// </summary>
		/// <returns>: a reference to an object of type Guitar</returns>
		Guitar& deString();

		/// <summary>
		/// A query that checks in the guitar object has at least one string
		/// </summary>
		/// <returns>: true if Guitar has at least one string, false otherwise</returns>
		bool isStrung() const;

		/// <summary>
		/// A query that inserts the object into the parameter of the current instance
		/// </summary>
		/// <param name="out">: a reference to an object type std::ostream</param>
		/// <returns>a reference of the parameter</returns>
		std::ostream& display(std::ostream& out = std::cout) const;
	};

}
#endif // !SENECA_GUITAR_H

