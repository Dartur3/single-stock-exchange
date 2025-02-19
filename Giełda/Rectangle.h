#pragma once
#include "Figure.h"
class Rectangle : public Figure <sf::RectangleShape>
{

	// sf::RectangleShape shape;

public:

	Rectangle();

	~Rectangle();

	Rectangle(double x, double y, double z, double w, sf::Color color, sf::Color fillColor, int thickness);

	void draw(sf::RenderTarget& target, sf::RenderStates state) const /* override*/;


};

