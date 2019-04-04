#include <iostream>
#include <string>
#include "AppleProduct.h"
#include "AppleStore.h"

using namespace cs31;

//actually declaring everything declared by applestore.h

AppleProduct AppleStore::buyWatch1(std::string color)
{
	AppleProduct item(AppleProduct::WATCH, "1", color, 249);
	return item;
}

AppleProduct AppleStore::buyWatch3(std::string color)
{
	AppleProduct item(AppleProduct::WATCH, "3", color, 329);
	return item;
}

AppleProduct AppleStore::buyiPad(std::string color, int gigabytes)
{
	double cost;
	if(gigabytes == 32)
	{
		cost = 329;
	}
	else if(gigabytes == 128)
	{
		cost = 429;
	}
	else
	{
		throw std::logic_error("Incorrect gigabytes");
	}

	AppleProduct item(AppleProduct::IPAD, "", color, cost);
	return item;
}


AppleProduct AppleStore::buyiPadPro(std::string color, int gigabytes)
{
	double cost;
	if(gigabytes == 64)
	{
		cost = 649;
	}
	else if(gigabytes == 256)
	{
		cost = 799;
	}
	else if(gigabytes == 512)
	{
		cost = 999;
	}
	else
	{
		throw std::logic_error("Incorrect gigabytes");
	}

	AppleProduct item(AppleProduct::IPAD, "Pro", color, cost);
	return item;
}

AppleProduct AppleStore::buyiPhone8(std::string color, int gigabytes)
{
	double cost;
	if(gigabytes == 64)
	{
		cost = 699;
	}
	else if(gigabytes == 256)
	{
		cost = 849;
	}
	else
	{
		throw std::logic_error("Incorrect gigabytes");
	}

	AppleProduct item(AppleProduct::IPHONE, "8", color, cost);
	return item;
}

AppleProduct AppleStore::buyiPhone8Plus(std::string color, int gigabytes)
{
	double cost;
	if(gigabytes == 64)
	{
		cost = 799;
	}
	else if(gigabytes == 256)
	{
		cost = 949;
	}
	else
	{
		throw std::logic_error("Incorrect gigabytes");
	}

	AppleProduct item(AppleProduct::IPHONE, "8Plus", color, cost);
	return item;
}

AppleProduct AppleStore::buyiPhoneX(std::string color, int gigabytes)
{
	double cost;
	if(gigabytes == 64)
	{
		cost = 999;
	}
	else if(gigabytes == 256)
	{
		cost = 1149;
	}
	else
	{
		throw std::logic_error("Incorrect gigabytes");
	}

	AppleProduct item(AppleProduct::IPHONE, "X", color, cost);
	return item;
}