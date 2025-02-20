#include "Point.h"

Point::Point() {}

Point::~Point() {}

Point::Point(double x, double y, double xd) : Figure(x, y, xd, sf::Color::White) {}

void Point::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(GetShape(), state);
}

/**
Point::Point(double x, double y)  : Figure(x, y, sf::Color::White)
{
	// shape.setPosition(x, y);
	shape.setRadius(this->circleRadius);
	// shape.setFillColor(sf::Color::White);
	//shape.setOrigin(this->circleRadius, this->circleRadius);
}  **/