#include "Exchange.h"
#include <iostream>
#include <algorithm>

Exchange::Exchange() {};

Exchange::Exchange(sf::Font& font, double price,std::map <std::string,int> cords) : stockPrice(price)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			orders[i][j].setFont(font);
			orders[i][j].setFillColor(sf::Color::White);
			orders[i][j].setCharacterSize(15);
			orders[i][j].setString("txt");
			orders[i][j].setPosition(cords["ox"]+ 100 * i, cords["oy"] + 20 * j);
		}
	}
	for (int i = 0;i < 50;i++)
	{
		stockPrices.push_back(price);
	}
}

std::vector<Offer> Exchange::GetOffers() const
{
	return offers;
}

double Exchange::GetStockPrices(int a) const
{
	return stockPrices[a];
}

bool Exchange::IsBought(double price, int amount)
{
	for (int i = 0; i < offers.size(); i++)
	{
		if (price == offers[i].GetPrice())
		{
			if (amount == offers[i].GetAmount())
			{
				offers.erase(offers.begin() + i);
				return true;
			}
			else if (amount > offers[i].GetAmount())
			{
				amount -= offers[i].GetAmount();
				offers.erase(offers.begin() + i);
			}
			else if (amount < offers[i].GetAmount())
			{
				offers[i].LowerAmount(amount);
				return true;
			}
		}
	}
	return false;
}

void Exchange::erase(int i)
{
	offers.erase(offers.begin() + i);
}

void Exchange::Buys()
{

	buyOffers.clear();
	// std::cout << buyOffers.size() << std::endl;
	std::mutex mt;
	/**
	for (int i = 0; i < 10; i++)
	{
		mt.lock();
		double buy = stockPrice + (rand() % 50 - 35 + (double)(rand() % 100) / 100) / 10;
		int amount = rand() % 8;
		Offer p(buy, amount);
		buyOffers.push_back(p);
		mt.unlock();
	} **/
	
	// srand(time(NULL));
	//mt.lock();
	std::mt19937 mt_rand(time(0));
	for(int i = 0; i < 10;i++)
	{
		mt.lock();
		double buy = std::max(0.0, stockPrice + (rand() % 50 - 25 + (double)(rand() % 100) / 100) / 10); // buy += rand() % 3 - 1;
		int amount = mt_rand() % 1000 + 1;
		Offer p(buy,amount);
		buyOffers.push_back(p);
		if (IsBought(buyOffers[i].GetPrice(),buyOffers[i].GetAmount()))
		{
			stockPrice = buyOffers[i].GetPrice();
		}
		for(int i=4;i>0;i--)
		{
			orders[0][i].setString(orders[0][i - 1].getString());
			orders[1][i].setString(orders[1][i - 1].getString());
		}
		orders[1][0].setString(Cut(std::to_string(p.GetPrice()+mt_rand() % 10 - 10)));
		orders[0][0].setString(std::to_string(p.GetAmount()));
		mt.unlock();
	} 
	//mt.unlock();
	
	stockPrices.erase(stockPrices.begin());
	stockPrices.push_back(stockPrice); 
}

void Exchange::Sells()
{
	std::mt19937 mt_rand(time(0));
	std::mutex mt;
	for (int i = 0; i < 10; i++)
	{
		mt.lock();
		double buy = std::max(0.0 ,stockPrice + ( rand() % 50 - 25 + (double)(rand() % 100) / 100) / 10);
		int amount =  (mt_rand() % 2000)/2 + 1;
		Offer p(buy,amount);
		offers.push_back(p);
		if (offers.size() > 0)
		{
			for (int i = 4; i > 0; i--)
			{
				orders[2][i].setString(orders[2][i - 1].getString());
				orders[3][i].setString(orders[3][i - 1].getString());
			}
			orders[2][0].setString(Cut(std::to_string(p.GetPrice())));
			orders[3][0].setString(std::to_string(p.GetAmount()));
		}
		mt.unlock();
	}
}

sf::Text Exchange::GetOrders(int i, int j)
{
	return orders[i][j];
}

std::string Exchange::Cut(std::string z)
{
	std::smatch result;
	std::regex model("-*[0-9]+\.[0-9][0-9]");
	if (std::regex_search(z, result, model))
	{
		std::string a = result.str();
		return a;
	}
	return "";
}