#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "IceCream.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 2nd, 2024

const char* const INVALID_REASON__FLAVOUR = "Received bad value for flavour.";
const char* const INVALID_REASON__SCOOPS = "Received bad value for cntScoops";
const char* const INVALID_REASON__EXISTS = "Order already exits in Order";
const char* const INVALID_REASON__EMPTY = "Object not initialized.";
const char* const VALID_OBJECT = "The object contains valid data and can be used.";

namespace seneca {
	/// <summary>
		/// The object that contains the icecream shops till machine functions
		/// 
		/// Default: order = nullptr;
		/// </summary>
	class Vendor
	{
		/// <summary>
		/// A dynammically allocated array that stores the individual icecream orders
		/// </summary>
		IceCream* order;

		/// <summary>
		/// Number of items in the order array
		/// </summary>
		int orderCnt;

		double orderSubTotal;

		/// <summary>
		/// deallocates the memory, used in closeShop && startNewOrder
		/// </summary>
		void deallocateMemory();

		/// <summary>
		/// copies current contents and adds one to array. Returns true if resized.
		/// </summary>
		/// <param name=arr>The array to be resized</param>
		bool resizeArray();

		const double chocolateScoopPrice = 1.24;
		const double fruttiScoopPrice = 1.50;
		const double otherFlavourScoopPrice = 0.99;
		const double vanillaWafferPrice = 0.50;
	public:
		/// <summary>
		/// Deallocates any dynamic memory used by the object and sets it to an empty state.
		/// </summary>
		void startNewOrder();

		/// <summary>
		/// Creates a new icecream object and adds to the order list. Iff the flavour doesn't already exists && all parameters are valid
		/// </summary>
		/// <param name=flavour>The char array of the flavour ordered</param>
		/// <param name=cntScoops>Number of scoops in the order</param>
		/// <param name=isWaffer>True: In vanilla waffer, False: In plastic cup</param>
		void addToOrder(const char* flavour, int cntScoops, bool isWaffer);

		/// <summary>
		/// Print to scren the receipt of the customer's order: The icecreams in order, the details for the order and a breakdown of the price.
		/// </summary>
		void displayOrderReceipt() const;

		/// <summary>
		/// Initializes the object to a default value; order = nullptr;
		/// </summary>
		void openShop();

		/// <summary>
		/// Deallocates any dynamic memory used by the objec and sets it to an empty state. 
		/// </summary>
		void closeShop();
	};
}
#endif // !SENECA_VENDOR_H
