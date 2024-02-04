#include <iostream>
#include <iomanip>
#include "Vendor.h"
#include "IceCream.h"

using namespace std;
namespace seneca 
{
	void Vendor::deallocateMemory()
	{
		for (int i = 0; i < orderCnt; i++)
			delete[i] order;
	}

	bool Vendor::resizeArray()
	{
		bool exitFlag = false;
		if (orderCnt == 0)
		{
			order = new IceCream[orderCnt + 1];
			orderCnt++;
			exitFlag = true;
		}
		else if (orderCnt > 0)
		{
			IceCream* tmp = new IceCream[orderCnt + 1];
			for (int i = 0; i < orderCnt; i++)
				tmp[i] = order[i];

			order = tmp;
			exitFlag = true;
		}
		return exitFlag;
	}

	void Vendor::openShop()
	{
		deallocateMemory();
		order = nullptr;
		orderCnt = 0;
		order[orderCnt].updateObjStatus(INVALID_REASON__EMPTY);
	}

	void Vendor::startNewOrder()
	{
		openShop();
	}

	void Vendor::addToOrder(const char* flavour, int cntScoops, bool isWaffer)
	{
		const char* orderStatus;
		if (flavour == nullptr || flavour[0] == '\0')
			orderStatus = INVALID_REASON__FLAVOUR;
		else if (cntScoops < 1 || cntScoops > 3)
			orderStatus = INVALID_REASON__SCOOPS;
		else
			orderStatus = VALID_OBJECT;

		if (orderStatus = VALID_OBJECT)
		{
			resizeArray();
			order[orderCnt].updateObjContents(flavour, cntScoops, isWaffer);
			orderCnt++;
		}
	}
}