#ifndef W2_MOVIE_H
#define W2_MOVIE_H

#include <climits> // for INT_MAX
#include <string>

namespace seneca {

	/// <summary>
	/// A structure that encapsulates some information about a
	///   single movie.
	/// 
	/// The title of the movie is a dynamically-allocated array
	///   of characters. It requires that the programmer manages
	///   the memory (allocation and deallocation).
	/// </summary>
	struct Movie
	{
		char* m_title;
		int m_budget;
		long m_grossIncome;
		double m_rating;
	};

	/// <summary>
	/// Loads from a file a collection of movies. Each movie record
	///   in the file is stored on a single line in the format:
	///   `BUDGET,GROSS_INCOME,RATING,TITLE\n`
	/// 
	/// This function will open the file, and close it when finished reading.
	/// 
	/// If the program has a collection of movies already loaded, this
	///   function will deallocate the memory used by those movies, and then
	///   will attempt to load the data from file.
	/// 
	/// This function will allocate EXACTLY the amount of memory
	///   needed to store the collection of movies found in the file.
	/// 
	/// The collection of movies is a dynamically-allocated array
	///   of objects of type `Movie`.
	/// </summary>
	/// <param name="fileName">the file containing the collection of movies</param>
	/// <returns>true if the data was loaded successfully, false otherwise.</returns>
	bool loadData(const char* fileName);

	/// <summary>
	/// Load from the file information about a single movie, and
	///   store it in the parameter.
	/// 
	/// The file must be already opened before this function is called.
	/// </summary>
	/// <param name="aMovie">the object to populate with data extracted
	///   from the file.</param>
	/// <returns>true if data was successfully extracted, false otherwise.</returns>
	bool loadData(Movie &aMovie);

	/// <summary>
	/// Prints to screen the information about a single movie, in the format:
	///   `TITLE, BUDGET, $GROSS_INCOME, RATING\n`
	/// </summary>
	/// <param name="idx">the index in the collection of the movie whose info
	///   must be printed to screen.</param>
	/* TODO: add the prototype of the `display` function that receives as a parameter
	*         an object of type `int`, and doesn't return anything.
	*         Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - if the index is more or equal to 0 and less than the total number of movies
	*     existing in the collection, then print to screen the information about the movie
	*     at the index received as parameter.
	* - if the index is outside the boundaries of the array, print to screen the message
	*     `Index out of bounds.\n`
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

	/// <summary>
	/// Prints to screen all the movies from the collection starting with the index
	///   `startIdx` until (and including) the index `endIdx`.  The output will be
	///   in the following format:
	/// 
	///   `******** LABEL ****************\n`
	///   `>> MOVIE_AT_INDEX_START_IDX\n`
	///   `>> MOVIE_AT_INDEX_START_IDX + 1\n`
	///   `>> MOVIE_AT_INDEX_START_IDX + 2\n`
	///   `>> ...`
	///   `>> MOVIE_AT_INDEX_END_IDX\n`
	/// 
	/// If `endIdx` is outside the boundaries of the collection, this function will
	///   print all the movies until the end of the collection, and then stops.
	/// </summary>
	/// <param name="label">a C-string to be displayed before the list of movies.</param>
	/// <param name="startIdx">the index of the first movie from the collection to be
	///   shown. The default value of this parameter is `0`.</param>
	/// <param name="endIdx">the index of the last movie from the collection to be
	///   shown. The default value of this parameter is `INT_MAX`.</param>
	/* TODO: add the prototype of the `display` function that receives as parameters
	*         the address of an unmodifiable C-string, and two objects of type `int`.
	*         Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* display()
	* - print the label to screen in the format
	*     `******** LABEL ****************\n`
	* - in a loop, starting at `startIdx` and until `endIdx` (but not exceeding the
	*     boundaries of the collection)
	*   - print `>> `
	*   - call `seneca::display()` to print a single movie from a specific index.
	*
	* Documentation to read:
	* - `INT_MAX`    - https://en.cppreference.com/w/c/types/limits
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

	/// <summary>
	/// Deallocate all the dynamic memory used by the collection of movies.
	/// </summary>
	/* TODO: add the prototype of the `deallocateMemory` function.
	*         Implement it in the cpp file as described below.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* deallocateMemory()
	* - iterate over the collection of movies and deallocate the memory used by the
	*     title of each movie.
	* - deallocate the memory used by the array of movies.
	* - set the global pointer `g_colMovies` to null,
	*     and the global counter `g_cntMovies` to 0.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
}
#endif