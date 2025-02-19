#include "Offer.h"

Offer::Offer(double price, int amount) : price(price), uses(200), amount(amount) {}

Offer::~Offer() {};

double Offer::GetPrice()
{
	uses = uses - 1;
	return price;
}

int Offer::GetAmount()
{
	return amount;
}

void Offer::LowerAmount(int a)
{
	amount -= a;
}

int Offer::GetUses()
{
	return uses;
}
/*
std::string Cut(std::string z)
{
	std::smatch result;
	std::regex model("-*[0-9]+\.[0-9][0-9]");
	if (std::regex_search(z, result, model))
	{
		std::string a = "Obecna cena: $" + result.str();
		return a;
	}
	return "";
}*/