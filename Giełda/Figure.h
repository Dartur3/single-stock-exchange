#pragma once

#ifndef FIGURE_H
#define FIGURE_H
#define _CRT_SECURE_NO_WARNINGS

// #include "Functions.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <regex>


template <class T>
class Figure : public sf::Drawable
{
	T shape;
public:

	Figure();

	Figure(double x, double y, double xd, sf::Color color);

	Figure(double x, double y, double z, double w, sf::Color color, sf::Color fillColor, int thickness);

	void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	T GetShape() const
	{
		return shape;
	}

	bool Over(sf::Vector2i j);

	void SetColor(sf::Color colorIn, sf::Color colorOut)
	{
		shape.setFillColor(colorIn);
		shape.setOutlineColor(colorOut);
	}
};

#endif