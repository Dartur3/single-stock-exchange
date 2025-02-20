#include "Figure.h"

template <class T>
Figure<T>::Figure() {}

// Specjalizacja konstruktora dla sf::CircleShape - POPRAWIONE: USUNIĘTO delegację konstruktora!
template<>
Figure<sf::CircleShape>::Figure() {} // **USUNIĘTO: : Figure<sf::CircleShape>() **

// Specjalizacja konstruktora dla sf::CircleShape
template<>
Figure<sf::CircleShape>::Figure(double x, double y, double xd, sf::Color color) : Figure<sf::CircleShape>() // Delegacja do domyślnego konstruktora szablonowego (OK dla konstruktorów z parametrami)
{
    shape.setPosition(x, y);
    shape.setRadius(xd);
    shape.setFillColor(color);
}

// Specjalizacja konstruktora dla sf::RectangleShape - POPRAWIONE: USUNIĘTO delegację konstruktora!
template<>
Figure<sf::RectangleShape>::Figure() {} // **USUNIĘTO: : Figure<sf::RectangleShape>() **


// Specjalizacja konstruktora dla sf::RectangleShape
template<>
Figure<sf::RectangleShape>::Figure(double x, double y, double z, double w, sf::Color fillColor, sf::Color outlineColor, int thickness) : Figure<sf::RectangleShape>() // Delegacja do domyślnego konstruktora szablonowego (OK dla konstruktorów z parametrami)
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

template <class T>
bool Figure<T>::Over(sf::Vector2i j) { return false; } // Domyślna implementacja

// Specjalizacja metody Over dla sf::CircleShape
template<>
bool Figure<sf::CircleShape>::Over(sf::Vector2i j)
{
    sf::Vector2f center = shape.getPosition() + sf::Vector2f(shape.getRadius(), shape.getRadius()); // Środek koła
    float radius = shape.getRadius();
    sf::Vector2f mousePosF(static_cast<float>(j.x), static_cast<float>(j.y));
    float distance = std::sqrt(std::pow(mousePosF.x - center.x, 2) + std::pow(mousePosF.y - center.y, 2));
    return distance <= radius;
}


// Specjalizacja metody Over dla sf::RectangleShape
template<>
bool Figure<sf::RectangleShape>::Over(sf::Vector2i j)
{
    sf::FloatRect bounds = shape.getGlobalBounds();
    return bounds.contains(static_cast<float>(j.x), static_cast<float>(j.y));
}