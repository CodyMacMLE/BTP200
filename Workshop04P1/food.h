#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

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
	};
}

#endif