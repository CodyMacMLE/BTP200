#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "IceCream.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 2nd, 2024

namespace seneca
{
	void IceCream::updateObjContents(const char* flavour, int cntScoops, bool isWaffer, double unitPrice)
	{
		strcpy(i_flavour, flavour);
		i_cntScoops = cntScoops;
		i_hasVanillaWafer = isWaffer;
		i_unitPrice = unitPrice;
	}

	bool IceCream::exists(const char* flavour) const {
		bool exists = false;
		if (strcmp(i_flavour, flavour) == 0)
			exists = true;
		return exists;
	}

	void IceCream::getIceCream(char* flavour, int& cntScoops, bool& hasVanillaWaffer, double& unitPrice) const
	{
		strcpy(flavour ,i_flavour);
		cntScoops = i_cntScoops;
		hasVanillaWaffer = i_hasVanillaWafer;
		unitPrice = i_unitPrice;
	}
}