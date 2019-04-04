#ifndef APPLEPRODUCT_H
#define APPLEPRODUCT_H

namespace cs31
{
	class AppleProduct
	{
		//declaring enum first because private members need it
	public:
		enum Kind
		{
			NOTSPECIFIED,
			IPHONE,
			IPAD,
			WATCH
		};

	private:
		Kind m_kind;
		std::string m_version;
		std::string m_color;
		double m_cost;

	public:
		AppleProduct(Kind kind = NOTSPECIFIED, std::string version = "", std::string color = "", double cost = 0.0)
			: m_kind(kind), m_version(version), m_color(color), m_cost(cost)
		{
		}

		//forward declarations for functions
		std::string getVersion();
		std::string getColor();
		Kind getKind();
		double getCost();

		//void print();
	};
}

#endif