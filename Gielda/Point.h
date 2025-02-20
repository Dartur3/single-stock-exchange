#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
class Point : public Figure <sf::CircleShape>
{

    // sf::CircleShape shape;
    //const float circleRadius{ 2.5f };

public:

    Point();

    ~Point();

    Point(double x, double y, double xd);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const /* override*/;

    // Point() = delete;

};