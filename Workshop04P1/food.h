#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 4th, 2024

namespace seneca
{
	/// <summary>
	/// Stores information about a single food item.
	/// 
	/// For simplicity, we allow clients to directly access the data members
	///     and assume that any data they store into the attribute is valid.
	/// </summary>
	struct Food
	{
		/// <summary>
		/// The name of the food.
		/// </summary>
		char m_name[100 + 1];

		/// <summary>
		/// The wight of the food item in kilograms.
		/// </summary>
		int m_weight;

		/// <summary>
		/// Set the current instance in an empty state (no weight/no name).
		/// </summary>
		Food();

		/// <summary>
		/// A custom constructor that sets the attributes to the value of parameters.
		/// 
		/// This constructor assumes that the parameters are valid.
		/// </summary>
		Food(const char* name, int weight);

		/// <summary>
		/// Checks if one rFood object is the same to the lFood Object
		/// </summary>
		/// <param name="lFood">The Food object (L) for comparison</param>
		/// <param name="rFood">The Food object (R) for comparison</param>
		/// <returns></returns>
		friend bool operator==(Food& lFood, Food& rFood);
	};
}

#endif