#pragma once

#ifndef USER_H
#define USER_H
#define _CRT_SECURE_NO_WARNINGS
#include "Figure.h"
#include "Rectangle.h"
#include "Point.h"
#include <iostream>
#include <fstream>

class User
{

	double wealth; // wolna przestrzeñ
	double totalBalance[2]; // ca³kowity balans
	int amount;
	int trueOrNot;
	int transactionAmount;
	sf::Text tBuy;
	sf::Text tSell;
	sf::Text tTransaction;
	sf::Text tFreeSpace;
	sf::Text tBalance;
	sf::Text tChange;
	sf::Text tAmount;
	sf::Text tTransactionHistory;
	Rectangle rBuy;
	Rectangle rSell;
//	std::pair<Rectangle, Rectangle> rectangles;
	std::map<std::string, Rectangle> rectangles;
	sf::Text tHistory[5];

public:

	User();

	User(sf::Font& font, double z[4],std::map <std::string,int> cords);

	void Draw(sf::RenderWindow& window, double price);

	std::string Cut(std::string z);

	void Over(sf::Vector2i j, double price);

	std::string GetData();

	~User();

};

#endif