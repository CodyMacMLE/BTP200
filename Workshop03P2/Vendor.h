#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "IceCream.h"

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

		/// <summary>
		/// deallocates the memory, used in closeShop && startNewOrder
		/// </summary>
		void deallocateMemory();

		/// <summary>
		/// copies current contents and adds one to array. Returns true if resized.
		/// </summary>
		/// <param name=arr>The array to be resized</param>
		bool resizeArray();
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
