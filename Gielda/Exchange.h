#pragma once

#ifndef EXCHANGE_H
#define EXCHANGE_H
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <random>
#include "Offer.h"
#include "User.h"

class Exchange
{
	std::vector<Offer> offers;
	std::vector<Offer> buyOffers;
	std::vector<double> stockPrices;
	double stockPrice;
	bool switcher = true;
	sf::Text orders[4][5];
public:
	Exchange();

	Exchange(sf::Font& font, double price,std::map <std::string,int> cords);

	std::vector<Offer> GetOffers() const;

	double GetStockPrices(int a) const;

	bool IsBought(double price, int amount);

	void erase(int i);

	void Buys();

	void Sells();

	sf::Text GetOrders(int i, int j);

	std::string Cut(std::string z);
};

#endif