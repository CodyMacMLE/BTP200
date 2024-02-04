#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "IceCream.h"

namespace seneca
{
	void IceCream::updateObjStatus(const char* const status)
	{
		i_objectStatus = status;
	}

	void IceCream::updateObjContents(const char* flavour, int cntScoops, bool isWaffer)
	{
		strcpy(i_flavour, flavour);
		i_cntScoops = cntScoops;
		i_hasVanillaWafer = isWaffer;
	}
}