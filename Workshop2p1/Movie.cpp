#include <iostream>
#include <string>
#include "Movie.h"
#include "DataHandle.h"

using namespace std;

namespace seneca {

	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	Movie* g_colMovies = nullptr;

	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	int g_cntMovies = 0;

	// TODO: define below all the functions from this module

	/* TODO: add the prototype of the `loadData` function that receives as a parameter
	*         the address of an unmodifiable C-string and returns a Boolean value.
	*         Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - check if there are movies already loaded. If "yes", call the function
	*     `seneca::deallocateMemory()` to discard the old collection.
	* - open the file whose name was received as parameter (use `seneca::openFile`).
	*     If the file cannot be open, exit the function with `false`.
	* - using `seneca::getRecordsCount()`, retrieve the number of movies that exists
	*     in the file. Store this number in a global variable.
	* - allocate a dynamic array of `Movie` objects able to store all the records from
	*     the file.  Store the address of this array in a global variable.
	* - in a loop, load from file one movie at a time and store the info in the array.
	*     Use `seneca::loadData` overload to retrieve a single record from file.
	* - close the file and exit with `true`.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool loadData(const char* fileName)
	{
		bool exitFlag = false;
		if (g_colMovies)
		{
			//deallocateMemory();
		}
		else 
		{
			bool status = openFile(fileName);
			if (status)
			{
				g_cntMovies = getRecordsCount();
				g_colMovies = new Movie[g_cntMovies];
				for (int i = 0; i < g_cntMovies; i++)
				{
					loadData(g_colMovies[i]);
				}
				closeFile();
				exitFlag = true;
			}
		}
		return exitFlag;
	}

	/* TODO: add the prototype of the `loadData` function that receives as a parameter
	*         a reference to an object of type `Movie` and returns a Boolean value.
	*         Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* loadData()
	* - using `seneca::read()` function implemented in the other module, extract
	*     from the file the *budget*, the *gross income*, the *rating*, and the *title*
	*     of a movie (IN THIS ORDER).  Store the extracted data in the attributes of
	*     the parameter.  Make sure to use the appropriate delimiters for each token.
	* - if all the `seneca::read()` functions called above were successful, return
	*     `true`, `false` otherwise.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool loadData(Movie &aMovie)
	{
		bool exitFlag = false;
		int budget; 
		int grossIncome;
		double rating;
		
		bool bFlag = read(budget);
		bool iFlag = read(grossIncome);
		bool rFlag = read(rating);
		char* title = read(' ');

		aMovie.m_title = title;
		aMovie.m_budget = budget;
		aMovie.m_grossIncome = grossIncome;
		aMovie.m_rating = rating;

		if (title != nullptr && bFlag && iFlag && rFlag)
		{
			exitFlag = true;
		}
		return exitFlag;
	}
}