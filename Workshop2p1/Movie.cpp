#include <iostream>
#include <string>
#include "Movie.h"
#include "DataHandle.h"

/// Cody MacDonald
/// cmacdonald33@senecacollege.ca
/// 159702232
/// January 24th, 2024

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

	bool loadData(const char* fileName)
	{
		bool exitFlag = false;
		if (g_colMovies != nullptr)
		{
			deallocateMemory();
		}
		
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
		
		return exitFlag;
	}

	bool loadData(Movie &aMovie)
	{
		bool exitFlag = false;
		int budget = 0; 
		int grossIncome = 0;
		double rating = 0.0;
		
		bool bFlag = read(budget);
		bool iFlag = read(grossIncome);
		bool rFlag = read(rating);
		char* title = read('\n');

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
	void display(int idx)
	{
		if (idx >= 0 && idx < g_cntMovies)
		{
			cout << g_colMovies[idx].m_title << ", " << g_colMovies[idx].m_budget << ", $" << g_colMovies[idx].m_grossIncome << ", " << g_colMovies[idx].m_rating << endl;
		}
		else
		{
			cout << "Index out of bounds.\n";
		}
	}

	void display(const char* label, int startIdx, int endIdx)
	{
		cout << "******** " << label << " ****************\n";
		for (int i = startIdx; i <= endIdx && i < g_cntMovies; i++)
		{
			cout << ">> ";
			display(i);
		}
	}
	void deallocateMemory()
	{
		for (int i = 0; i < g_cntMovies; i++)
		{
			delete [] g_colMovies[i].m_title;
		}
		delete [] g_colMovies;
		g_colMovies = nullptr;
		g_cntMovies = 0;
	}
}