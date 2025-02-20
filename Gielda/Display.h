#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H
#define _CRT_SECURE_NO_WARNINGS

#include "Exchange.h"
#include <map>

class Display
{
	Exchange exchange;
	Point point0;
	sf::Text tPricePlus15;
	sf::Text tPriceMinus15;
	sf::Text tCurrentPrice;
	sf::Text tOrderBook;
	sf::Text tOrderBookInfo;
	std::map<int,Rectangle> rectangle;
	User user;
public:
	~Display();

	Display();

	Display(sf::Font& font, double z[4],std::map <std::string,int> cords);

	Exchange* GetExchange();

	void GenerateChart(sf::RenderWindow& window,std::map <std::string,int> cords);

	sf::Text getText(int a);

	void work();

	void Over(sf::Vector2i j);

};

#endif