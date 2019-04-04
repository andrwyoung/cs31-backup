#include <iostream>
#include <string>
#include "AppleProduct.h"

using namespace cs31;

//actually declaring the functions declared in appleproduct.h (which all happen to be GET functions)

AppleProduct::Kind AppleProduct::getKind()
{
	return m_kind;
}

std::string AppleProduct::getVersion()
{
	return m_version;
}

std::string AppleProduct::getColor()
{
	return m_color;
}

double AppleProduct::getCost()
{
	return m_cost;
}

/*
void AppleProduct::print()
{
	std::cout << "m_kind: " << m_kind << '\n';
	std::cout << "m_version: " << m_version << '\n';
	std::cout << "m_color: " << m_color << '\n';
	std::cout << "m_cost: " << std::to_string(m_cost) << "\n\n";
}
*/

