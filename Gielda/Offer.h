#pragma once

#ifndef OFFER_H
#define OFFER_H
#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include "Rectangle.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include <random>
#include <regex>


class Offer
{
	int uses;
	double price;
	int amount;

public:

	Offer(double price,int amount);

	~Offer();

	double GetPrice();

	int GetAmount();

	void LowerAmount(int a);

	int GetUses();
};

#endif