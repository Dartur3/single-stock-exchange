#include "Point.h"
#include "Exchange.h"
#include "Display.h"

int main()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

	double z[4] = {100,0,100,0};
	std::ifstream myFile("Save");
	if(myFile)
	{
	    myFile >> z[0] >> z[1] >> z[2] >> z[3];
	}
	myFile.close();

    srand(time(NULL));
    Point point(100, 100, 5);
    // Point point();
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Gielda");
    window.setFramerateLimit(60);
    sf::Event event;
    int time = 10;
    int y = 100;
    std::map <std::string, int> cords;
    cords["bx"] = 800; cords["by"] = 20;
    cords["tx"] = 800; cords["ty"] = 184;
    cords["ox"] = 800; cords["oy"] = 350;
    cords["sx"] = 510; cords["sy"] = 50;
    cords["wx"] = 10;  cords["wy"] = 170;
    Display gielda(font,z,cords);
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
			{
				gielda.Over(sf::Mouse::getPosition(window));
			}	
        }
        time--;
        if (time < 1)
        {
            gielda.work();
            time = 10;
        }
        gielda.GenerateChart(window,cords);
      //  sf::RectangleShape shape; shape.setSize((sf::Vector2f(50, 20))); shape.setPosition(560, 20); shape.setFillColor(sf::Color::Black); sf::RectangleShape shape2 = shape;  shape2.setPosition(560, 300);
     //   window.draw(shape); window.draw(shape2);
        window.display();
    }
}