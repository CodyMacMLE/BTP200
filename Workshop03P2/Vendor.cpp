#include <iostream>
#include <iomanip>
#include "Vendor.h"
#include "IceCream.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 2nd, 2024

using namespace std;
namespace seneca 
{
	void Vendor::deallocateMemory()
	{
			delete[] order;
	}

	bool Vendor::resizeArray()
	{
		bool exitFlag = false;
		if (orderCnt == 0)
		{
			order = new IceCream[orderCnt + 1];
			exitFlag = true;
		}
		else if (orderCnt > 0)
		{
			IceCream* tmp = new IceCream[orderCnt + 1];
			for (int i = 0; i < orderCnt; i++)
				tmp[i] = order[i];
			delete[] order;

			order = tmp;
			exitFlag = true;
		}
		return exitFlag;
	}

	void Vendor::openShop()
	{
		order = nullptr;
		orderCnt = 0;
		orderSubTotal = 0.0;
	}

	void Vendor::startNewOrder()
	{
		deallocateMemory();
		openShop();
	}

	void Vendor::addToOrder(const char* flavour, int cntScoops, bool isWaffer)
	{
		double tempOrderPrice = 0.0;
		const char* orderStatus;
		bool exists = false;
		for (int i = 0; i < orderCnt; i++) {
			if (order[i].exists(flavour))
			{
				exists = true;
			}
		}

		if (flavour == nullptr || flavour[0] == '\0')
			orderStatus = INVALID_REASON__FLAVOUR;
		else if (cntScoops < 1 || cntScoops > 3)
			orderStatus = INVALID_REASON__SCOOPS;
		else if (exists)
			orderStatus = INVALID_REASON__EXISTS;
		else
			orderStatus = VALID_OBJECT;

		if (orderStatus == VALID_OBJECT)
		{
			if (strcmp("Chocolate", flavour) == 0)
				tempOrderPrice = chocolateScoopPrice * cntScoops;
			else if (strcmp("Tutti Frutti", flavour) == 0)
				tempOrderPrice = fruttiScoopPrice * cntScoops;
			else
				tempOrderPrice = otherFlavourScoopPrice * cntScoops;

			if (isWaffer)
				tempOrderPrice += vanillaWafferPrice;

			resizeArray();
			order[orderCnt].updateObjContents(flavour, cntScoops, isWaffer, tempOrderPrice);
			orderSubTotal += tempOrderPrice;
			orderCnt++;
		}
	}

	void Vendor::displayOrderReceipt() const
	{
		double orderTax = orderSubTotal * 0.13;
		double totalPrice = orderSubTotal + orderTax;
		cout << "\n*********** Customer Receipt Copy ***********" << endl;
		for (int i = 0; i < orderCnt; i++)
		{
			char flavour[30];
			int numScoops;
			bool isWaffer;
			double unitPrice = 0.0;
			double scoopPrice = 0.0;
			order[i].getIceCream(flavour, numScoops, isWaffer, unitPrice);
			if (isWaffer)
				scoopPrice = (unitPrice - vanillaWafferPrice) / numScoops;
			else
				scoopPrice = unitPrice / numScoops;

			cout.fill('.');
			cout.precision(3);
			cout << setiosflags(ios::showpoint);
			// First Line
			cout << "#" << i + 1 << ". ";
			cout.width(32);
			cout << left << flavour;
			cout.width(9);
			cout << right << unitPrice << endl;
			// Second Line
			cout.fill(' ');
			cout.width(7);
			if (!isWaffer)
			{
				cout << numScoops << " scoops @ ";
				cout.width(4);
				if (scoopPrice < 1)
					cout.precision(2);
				cout << scoopPrice;
				cout.precision(3);
				cout << " each";
				cout.fill('.');
				cout.width(10);
				if (scoopPrice * numScoops < 1)
					cout.precision(2);
				cout << scoopPrice * numScoops << endl;
				cout.precision(3);;
			}
			else
			{
				cout << numScoops << " scoops @ ";
				cout.width(4);
				if (scoopPrice < 1)
					cout.precision(2);
				cout << scoopPrice;
				cout.precision(3);
				cout << " each";
				cout.fill('.');
				cout.width(10);
				if (scoopPrice * numScoops < 1)
					cout.precision(2);
				cout << scoopPrice * numScoops << endl;
				cout.precision(3);
				cout << "      Wafer.....................0.50" << endl;
			}
		}
		cout << "\n\n";
		/// Subtotal Line
		cout.fill(' ');
		cout.width(35);
		cout << "Price before tax";
		cout.fill('.');
		cout.width(10);
		if (orderSubTotal > 9.9)
			cout.precision(4);
		cout << orderSubTotal << endl;
		cout.precision(3);
		/// Tax Line
		cout.fill(' ');
		cout.width(35);
		cout << "Tax";
		cout.fill('.');
		cout.width(10);
		if (orderTax < 1)
			cout.precision(2);
		cout << orderTax << endl;
		cout.precision(3);
		/// Order Total Line
		cout.fill(' ');
		cout.width(35);
		cout << "Price with tax";
		cout.fill('.');
		cout.width(10);
		if (totalPrice > 9.9)
			cout.precision(4);
		cout << totalPrice << endl;
		cout.precision(3);
		cout << "*********************************************" << endl;

		cout.fill('*');
		cout.precision(6);
	}

	void Vendor::closeShop()
	{
		deallocateMemory();
		order = nullptr;
		orderCnt = 0;
		orderSubTotal = 0.0;
	}
}