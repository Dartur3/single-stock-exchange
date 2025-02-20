#include "Rectangle.h"

Rectangle::Rectangle() {}

Rectangle::~Rectangle() {}

Rectangle::Rectangle(double x, double y, double z, double w, sf::Color fillColor, sf::Color outlineColor, int thickness) : Figure(x, y, z, w, fillColor, outlineColor, thickness) {}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(GetShape(), state);
}