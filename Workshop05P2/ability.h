#ifndef SENECA_ABILITY_H
#define SENECA_ABILITY_H

namespace seneca {
	class Ability {
		/// <summary>
		/// The name of an ability
		/// </summary>
		char a_abilityName[100 + 1];

		/// <summary>
		/// The power of the ability
		/// </summary>
		int a_strength;
	public:

		/// <summary>
		/// Default constructor of the Ability class
		/// </summary>
		/// <param name="name">The name of the ability</param>
		/// <param name="strength">The strength of the ability</param>
		Ability(const char* name = "", int strength = 0);

		/// <summary>
		/// Checks if ability object exists: true if exists, false if empty.
		/// </summary>
		operator bool() const;
	};
}
#endif // !SENECA_ABILITY_H

