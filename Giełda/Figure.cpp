#include "Figure.h"

template <class T>
Figure<T>::Figure() {}

Figure<sf::CircleShape>::Figure() {}

Figure<sf::CircleShape>::Figure(double x, double y, double xd, sf::Color color)
{
	shape.setPosition(x, y);
	shape.setRadius(xd);
	shape.setFillColor(color);
};

Figure<sf::RectangleShape>::Figure() {}

Figure<sf::RectangleShape>::Figure(double x, double y, double z, double w, sf::Color fillColor, sf::Color outlineColor, int thickness)
{
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(z, w));
	shape.setFillColor(fillColor);
	shape.setOutlineColor(outlineColor);
	shape.setOutlineThickness(thickness);
}

template <class T>
void Figure<T>::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

/*template <class T>
T Figure<T>::GetShape() const
{
	return shape;
}
/*template <class T>
Figure<T>::Figure(double x, double y, sf::Color color)
{
	shape.setFillColor(color);
	shape.setPosition(x, y);
}*/


	template <class T>
	bool Figure<T>::Over(sf::Vector2i j) {}

	bool Figure<sf::CircleShape>::Over(sf::Vector2i j)
	{
		if (j.x > shape.getPosition().x and j.x< shape.getPosition().x + shape.getRadius() * 2 and j.y>shape.getPosition().y and j.y < shape.getPosition().y + shape.getRadius() * 2) return true;
		else return false;
	}

	bool Figure<sf::RectangleShape>::Over(sf::Vector2i j)
	{
		if (j.x > shape.getPosition().x and j.x< shape.getPosition().x + shape.getSize().x and j.y>shape.getPosition().y and j.y < shape.getPosition().y + shape.getSize().y) return true;
		else return false;
	}

	/*template <class T>
	void Figure<T>::SetColor(sf::Color colorIn, sf::Color colorOut)
	{
		shape.setFillColor(colorIn);
		shape.setOutlineColor(colorOut);
	}*/
