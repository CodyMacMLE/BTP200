#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 2nd, 2024

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
		/// The price of the single unit of icecream
		/// </summary>
		double i_unitPrice;

	public:
		/// <summary>
		/// Update the private members of the boject icecream
		/// </summary>
		/// <param name="flavour">flavour of Icecream</param>
		/// <param name="cntScoops">Number of scoops</param>
		/// <param name="isWaffer">True if icecream is in a waffer, false otherwise</param>
		void updateObjContents(const char* flavour, int cntScoops, bool isWaffer, double unitPrice);
		
		/// <summary>
		/// Checks if the flavour exists
		/// </summary>
		/// <param name="flavour">flavour of icecream to compare</param>
		bool exists(const char* flavour) const;

		/// <summary>
		/// return the parameters flavour, count of scoops, and in Waffer (true) or not (false)
		/// </summary>
		/// <param name="flavour">The flavour</param>
		/// <param name="cntScoops">The number of scoops in the order</param>
		/// <param name="hasVanillaWaffer">Whether the order is in a waffer (t) or not (f)</param>
		void getIceCream(char* flavour, int& cntScoops, bool& hasVanillaWaffer, double& unitPrice) const;	
	};
}
#endif // !SENECA_ICECREAM_H

