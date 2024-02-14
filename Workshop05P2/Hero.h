#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "ability.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

namespace seneca {
	class Hero {

		/// <summary>
		/// Dynamic array that stores the name of the hero
		/// </summary>
		char* m_name;

		/// <summary>
		/// A Dynamic array that stores all the abilities of the hero
		/// </summary>
		Ability* m_abilities;

		/// <summary>
		/// An int that stores the count of abilites in m_abilities
		/// </summary>
		int m_cntAbilities;

		/// <summary>
		/// Stores the level of the hero (higher level = great power). Empty state is when level is 0.
		/// </summary>
		int m_level;

	public:

		/// <summary>
		/// Initializes the object to an empty state
		/// </summary>
		Hero();

		/// <summary>
		/// Custom constructor of hero
		/// </summary>
		/// <param name="name">The name of the hero</param>
		/// <param name="abilities">an array of object Ability to add to the hero</param>
		/// <param name="cntAbilities">number of abilites added in the array</param>
		Hero(const char* name, const Ability* abilities, int cntAbilities);

		/// <summary>
		/// Destructor handling m_name and m_abilites
		/// </summary>
		~Hero();

		/// <summary>
		/// checks whether Hero exists: true if exists, false otherwise.
		/// </summary>
		operator bool() const;

		/// <summary>
		/// Returns the name of the Hero
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// a conversion to int operator that returns the total strength a hero has
		/// </summary>
		operator int () const;

		/// <summary>
		/// a modifier that adds a new ability to the array of abilities a hero has (resize the array whose address is stored in m_abilities)
		/// </summary>
		/// <param name="Ability">an unmodifiable reference to an object of type Ability</param>
		/// <returns>a reference to an object of type Hero</returns>
		Hero& operator += (const Ability& ability);

		/// <summary>
		/// a modifier that changes the level of the hero by the value received as parameter. If the parameter is negative, the new level of the hero cannot go below 1.
		/// </summary>
		/// <param name="lvlchange">an object of type int representing the number of levels to be added to the hero's level.</param>
		/// <returns>a reference to an object of type Hero</returns>
		Hero& operator += (int lvlchange);

		/// <summary>
		///  a modifier that increases the level of the hero by 1.
		/// </summary>
		/// <returns>a reference to an object of type Hero</returns>
		Hero& operator ++ ();

		/// <summary>
		/// a query that prints to the screen the content of the current instance
		/// </summary>
		void display() const;
	};

	/// <summary>
	/// compares the power of two heroes
	/// </summary>
	/// <param name="h1">an unmodifiable reference to an object of type Hero</param>
	/// <param name="h2">an unmodifiable reference to an object of type Hero</param>
	/// <returns>returns true if the strength of the hero received as the first parameter is smaller than the strength of the hero received as the second parameter; false otherwise.</returns>
	bool operator< (const Hero& h1, const Hero& h2);

	/// <summary>
	/// compares the power of two heroes
	/// </summary>
	/// <param name="h1">an unmodifiable reference to an object of type Hero</param>
	/// <param name="h2">an unmodifiable reference to an object of type Hero</param>
	/// <returns> returns true if the strength of the hero received as the first parameter is greater than the strength of the hero received as the second parameter; false otherwise.</returns>
	bool operator> (const Hero& h1, const Hero& h2);

	/// <summary>
	/// adds to the hero received as the second parameter the ability received as the first parameter.
	/// </summary>
	/// <param name="ability">an unmodifiable reference to an object of type Ability</param>
	/// <param name="hero">a reference to an object of type Hero</param>
	/// <returns>a reference to type Hero</returns>
	Hero& operator>> (const Ability& ability, Hero& hero);

	/// <summary>
	/// adds to the hero received as the first parameter the ability received as the second parameter.
	/// </summary>
	/// <param name="ability">an unmodifiable reference to an object of type Ability</param>
	/// <param name="hero">a reference to an object of type Hero</param>
	/// <returns>a reference to type Hero</returns>
	Hero& operator<< (Hero& hero, const Ability& ability);
}

#endif // !SENECA_HERO_H
