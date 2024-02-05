#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H
#include <iostream>
#include "food.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 4th, 2024

namespace seneca {

	class Fridge {
		/// <summary>
		/// The maximum capacity of a fridge in Kg
		/// </summary>
		int m_capacity;

		/// <summary>
		/// A dynamically stored array that represents the model of the fridge
		/// </summary>
		char* m_model;

		/// <summary>
		/// The dynamically stored array of type Food of all the food stored in the fridge
		/// </summary>
		Food* m_foods;

		/// <summary>
		/// The quantity of food items in the fridge
		/// </summary>
		int m_cntFoods;
	public:
		/// <summary>
		/// The default constructor of Fridge (m_capacity = 10, m_model = nullptr, m_foods = nullptr, m_cntFoods = 0)
		/// </summary>
		Fridge();

		/// <summary>
		/// A custom constructor of Fridge (m_capacity = capacity, m_model = model, m_foods = nullptr, m_cntFoods = 0)
		/// </summary>
		/// <param name="model">a const char array of the model name</param>
		/// <param name="capacity">an int over 10 that designates the fridge capacity (Kg)</param>
		Fridge(const char* model, int capacity);

		/// <summary>
		/// A custom constructor of Fridge (m_capacity = capacity, m_model = model, m_foods = foods, m_cntFoods = cntFoods)
		/// </summary>
		/// <param name="foods">an array of type Food</param>
		/// <param name="cntFoods">The size of the array of type food "foods"</param>
		/// <param name="model">a const char array of the model name</param>
		/// <param name="capacity">an int over 10 that designates the fridge capacity (Kg)</param>
		Fridge(Food* foods, int cntFoods, const char* model, int capacity);

		/// <summary>
		/// The deconstructor to remove the dynamically stored arrays of m_model and m_foods
		/// </summary>
		~Fridge();

		/// <summary>
		/// A query that iterates over the food in m_foods and summates m_weight.
		/// </summary>
		/// <returns>The summation of the food in Fridge (int)</returns>
		int getContentWeight() const;

		/// <summary>
		/// a modifier that adds a new Food object into the fridge if there is capacity
		/// </summary>
		/// <param name="aFood">a single Food object</param>
		/// <returns>True: if the object was added, False: otherwise</returns>
		bool addFood(Food aFood);

		/// <summary>
		/// sets the model of the current Fridge object
		/// </summary>
		/// <param name="model">a const char array of the model name</param>
		/// <param name="capacity">an int over 10 that designates the fridge capacity (Kg)</param>
		void setModel(const char* model, int capacity);

		/// <summary>
		/// Checks if the current Fridge object is full
		/// </summary>
		/// <returns>True if fridge is at least 90% full, false otherwise</returns>
		bool isFull() const;

		/// <summary>
		/// Checks if the Fridge object contains a Food
		/// </summary>
		/// <param name="theFood">The Food object to compare</param>
		/// <returns>True if Fridge contains theFood object, False otherwise</returns>
		bool hasFood(const char* theFood = "\0") const;

		/// <summary>
		/// A query that inserts into the parameter the content of the current instance
		/// </summary>
		/// <param name="out">a reference to an object of type std::ostream</param>
		/// <returns>a reference to the object received as parameter</returns>
		std::ostream& display(std::ostream& out = std::cout) const;
	};
}
#endif
