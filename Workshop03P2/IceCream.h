#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
//

namespace seneca
{
	/// <summary>
	/// A class containing a single icecream a customer has ordered
	/// </summary>
	class IceCream
	{	
		/// <summary>
		/// A static char array storing the flavour
		/// </summary>
		char i_flavour[30];

		/// <summary>
		/// The number of scoops for this order
		/// </summary>
		int i_cntScoops;

		/// <summary>
		/// True: if in a vanilla wafer, False: if in a plastic cup
		/// </summary>
		bool i_hasVanillaWafer;

		/// <summary>
		/// Current status of the object
		/// </summary>
		const char* i_objectStatus;

	public:
		void updateObjContents(const char* flavour, int cntScoops, bool isWaffer);
		void updateObjStatus(const char* const status);

	};
}
#endif // !SENECA_ICECREAM_H

