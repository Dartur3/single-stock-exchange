#include "Display.h"

Display::Display() {};

Display::~Display()
{
	std::ofstream myFile;
	myFile.open("Save");
	myFile << user.GetData() << ' ' << exchange.GetStockPrices(49);
	myFile.close();
}

Display::Display(sf::Font& font, double z[4],std::map <std::string,int> cords) : exchange(font,z[3],cords), point0(cords["wx"]+485, cords["wy"] - 5,5), user(font,z,cords)
{
	Rectangle r0(cords["wx"], cords["wy"] - 78, 490, 52, sf::Color::Transparent, sf::Color(100, 100, 100), 1 ); rectangle[0] = r0;
	Rectangle r1(cords["wx"], cords["wy"] + 26, 490, 52, sf::Color::Transparent, sf::Color(100, 100, 100), 1); rectangle[1] = r1;
	Rectangle r2(cords["wx"], cords["wy"] - 130, 490, 260, sf::Color::Transparent, sf::Color::White, 1); rectangle[2] = r2;
	Rectangle r3(cords["ox"] + 178, cords["oy"] - 27, 0, 128, sf::Color::Transparent, sf::Color(100, 100, 100), 1); rectangle[3] = r3;
	Rectangle r4(cords["ox"]-5, cords["oy"]-27, 365, 128, sf::Color::Transparent, sf::Color::White, 2); rectangle[4] = r4;
	tPricePlus15.setFont(font);
	tPricePlus15.setFillColor(sf::Color::White);
	tPricePlus15.setPosition(cords["wx"] + 490, cords["wy"] - 150);
	tPricePlus15.setCharacterSize(15);
	tPriceMinus15 = tPricePlus15;
	tPriceMinus15.setPosition(cords["wx"] + 490, cords["wy"] + 130);
	tCurrentPrice = tPricePlus15;
	tCurrentPrice.setPosition(cords["wx"], cords["wy"] - 163);
	tCurrentPrice.setCharacterSize(20);
	tOrderBook = tCurrentPrice;
	tOrderBook.setPosition(cords["ox"], cords["oy"] - 50);
	tOrderBook.setString("Order Book");
	tOrderBookInfo = tPricePlus15;
	tOrderBookInfo.setPosition(cords["ox"], cords["oy"] - 25);
	tOrderBookInfo.setString("Bid Vol.		Purchase ($)		Sale ($)			Ask Vol.");

}

Exchange* Display::GetExchange()
{
	return &exchange;
}

void Display::GenerateChart(sf::RenderWindow& window,std::map <std::string,int> cords)
{
	tPricePlus15.setString(exchange.Cut(std::to_string(exchange.GetStockPrices(49) + 15)));
	tPriceMinus15.setString(exchange.Cut(std::to_string(exchange.GetStockPrices(49) - 15)));
	tCurrentPrice.setString("Current price: $" + exchange.Cut(std::to_string(exchange.GetStockPrices(49))));
	/**
	for (int i = 0;i < z1.size() ;i++)
	{
		if (z1[i] == '.')
		{
			for (int j = z1.size();j > i + 3;j--)
			{
				z1.erase(z1.begin() + j - 1);
			}
			break;
		}
	} **/
	// txt3.setString("Obecna cena: $" + wynik[0]); // +std::to_string((double)((int)(exchange.GetStockPrices(49) * 100)) / 100));

	int z = exchange.GetOffers().size();
	for (int i = 0; i < z; i++)
	{
		if (exchange.GetOffers()[i].GetUses() < 1)
		{
			exchange.erase(i);
		}
		z = exchange.GetOffers().size();

	}

	// std::vector<sf::Vertex> line(stockPrices.size());
	sf::Vertex line[50];
	for (int i = 0;i < 50;i++)
	{
		double z = cords["wy"] - 10 * (exchange.GetStockPrices(i) - exchange.GetStockPrices(49));
		if (z < cords["wy"] - 130) z = cords["wy"] - 130;
		if (z > cords["wy"] + 130) z =  cords["wy"] + 131;

		line[i] = sf::Vertex(sf::Vector2f(cords["wx"] + 10 * i, z));
	}
	window.draw(rectangle[0]);
	window.draw(rectangle[1]);
	window.draw(line, 50, sf::LineStrip);
	window.draw(tPricePlus15);
	window.draw(tPriceMinus15);
	window.draw(tCurrentPrice);
	window.draw(tOrderBook);
	window.draw(tOrderBookInfo);
	window.draw(rectangle[2]);
	window.draw(rectangle[3]);
	window.draw(rectangle[4]);
	window.draw(point0);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			window.draw(exchange.GetOrders(i,j));
		}
	}
	user.Draw(window,exchange.GetStockPrices(49));
}

sf::Text Display::getText(int a)
{
	if (a == 0) return tPricePlus15;
	else if (a == 1) return tPriceMinus15;
	else if (a == 2) return tCurrentPrice;
}

void Display::work()
{
//	exchange.Buys();
//	exchange.Sells();

	std::thread t4(&Exchange::Buys, &exchange);
	std::thread t5(&Exchange::Sells, &exchange);
	t4.join();
	t5.join();
}

void Display::Over(sf::Vector2i j)
{
	user.Over(j,exchange.GetStockPrices(49));
}