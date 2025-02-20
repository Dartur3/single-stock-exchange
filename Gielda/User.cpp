#include "User.h"
#include <map>
#include <SFML/Graphics.hpp>

User::User() {};

User::~User() {};

std::string User::GetData()
{
	std::string z = std::to_string(wealth) + ' ' + std::to_string(amount) + ' ' + std::to_string(totalBalance[1]);
	return z;
}

User::User(sf::Font& font, double z[4],std::map <std::string,int> cords)
	: wealth(z[0]), amount(z[1]), transactionAmount(0), trueOrNot(0),
	rBuy(cords["sx"]/*510*/, cords["sy"]/*50*/, 104, 52, sf::Color(7, 140, 3), sf::Color::Green, 3),
	rSell(cords["sx"], cords["sy"] + 62, 104, 52, sf::Color(140, 3, 3), sf::Color::Red, 3)
{
	Rectangle a(cords["sx"] + 34, cords["sy"] + 153, 15, 15, sf::Color::Transparent, sf::Color::Transparent, 1);
	rectangles["+"] = a;
	Rectangle b(cords["sx"] + 52, cords["sy"] + 153, 15, 15, sf::Color::Transparent, sf::Color::Transparent, 1);
	rectangles["-"] = b;
	Rectangle c(cords["tx"] - 5, cords["ty"] - 4, 365, 108, sf::Color::Transparent, sf::Color::White, 2);
	rectangles["TH"] = c;
	
	totalBalance[0] = z[2];
	totalBalance[1] = z[2];

	tBuy.setFont(font);
	tBuy.setFillColor(sf::Color::Green);
	tBuy.setPosition(cords["sx"] + 20, cords["sy"]+ 8);
	tBuy.setStyle(sf::Text::Bold);
	tBuy.setString("BUY");
	tSell.setFont(font);
	tSell.setFillColor(sf::Color::Red);
	tSell.setPosition(cords["sx"] + 15, cords["sy"] + 67);
	tSell.setStyle(sf::Text::Bold);
	tSell.setString("SELL");
	tTransaction.setFont(font);
	tTransaction.setString(std::to_string(transactionAmount) + "\n - +");
	tTransaction.setPosition(cords["sx"] + 30, cords["sy"] + 117);
	tTransaction.setCharacterSize(25);
	tFreeSpace.setFont(font);
	tFreeSpace.setCharacterSize(20);
	tFreeSpace.setPosition(cords["bx"] + 170, cords["by"]);
	tBalance = tFreeSpace;
	tBalance.setPosition(cords["bx"]/*800*/,cords["by"]/*20*/);
	tAmount = tFreeSpace;
	tAmount.setPosition(cords["bx"],cords["by"] + 80);
	tChange = tFreeSpace;
	tChange.setPosition(cords["bx"],cords["by"] + 40);
	tTransactionHistory = tFreeSpace;
	tTransactionHistory.setPosition(cords["tx"], cords["ty"] - 27);
	tTransactionHistory.setString("Transaction History");
	for(int i=0;i<5;i++)
	{
		tHistory[i] = tChange;
		tHistory[i].setCharacterSize(15);
		tHistory[i].setPosition(cords["tx"]/*800*/, cords["ty"]/*184*/ + i*20);
	}
}

void User::Draw(sf::RenderWindow& window, double price)
{
	tAmount.setString("Assets: " + std::to_string(amount));
	tFreeSpace.setString("Free space: $" + Cut(std::to_string(wealth)));
	double balance = wealth + amount * price;
	totalBalance[1] = balance;
	tBalance.setString("Balance: $" + Cut(std::to_string(balance)));
	if(balance > totalBalance[0])
	{
		tChange.setFillColor(sf::Color::Green);
	}
	else if (balance == totalBalance[0])
	{
		tChange.setFillColor(sf::Color::White);
	}
	else
	{
		tChange.setFillColor(sf::Color::Red);
	}
	tChange.setString("Change(+/-): " + Cut(std::to_string(balance - totalBalance[0])) + '(' + Cut(std::to_string((((balance - totalBalance[0]) / totalBalance[0])*100))) + "%)");
	if(totalBalance == 0)
	{
		tChange.setString("Change(+/-): " + Cut(std::to_string(balance - totalBalance[0])) + "(Inf. %)");
	}
	tTransaction.setString(std::to_string(transactionAmount) + "\n - +");
	window.draw(tFreeSpace);
	window.draw(tBalance);
	window.draw(rBuy);
	window.draw(rSell);
	window.draw(tBuy);
	window.draw(tSell);
	window.draw(tChange);
	window.draw(tAmount);
	window.draw(rectangles["TH"]);
	window.draw(tTransactionHistory);
	if (trueOrNot > 0)
	{
		window.draw(tTransaction);
		window.draw(rectangles["+"]);
		window.draw(rectangles["-"]);
	}
	for(int i = 0; i < 5; i++)
	{
		window.draw(tHistory[i]);
	}
}

std::string User::Cut(std::string z)
{
	std::smatch result;
	std::regex model("-*[0-9]+\.[0-9][0-9]");
	if (std::regex_search(z, result, model))
	{
		std::string a = result.str();
		return a;
	}
	return "";
}

void User::Over(sf::Vector2i j, double price)
{
	if (rBuy.Over(j))
	{
		if (trueOrNot == 0)
		{
			rBuy.SetColor(sf::Color(7, 110, 3),sf::Color::Green); //podswietlony
			transactionAmount = 0;
			trueOrNot = 1;
		}
		else if(trueOrNot == 1 and price * transactionAmount <= wealth)
		{
			trueOrNot = 0;
			rBuy.SetColor(sf::Color(7, 140, 3),sf::Color::Green); //stary kolor
			if(transactionAmount>0)
			{
			for(int i = 4; i > 0; i--)
				{
				tHistory[i].setString(tHistory[i-1].getString());
				}
			tHistory[0].setString("Bought " + std::to_string(transactionAmount) + " assets for $" + Cut(std::to_string(price)) + " each.");
			}
			amount += transactionAmount;
			wealth -= price * transactionAmount;
		}
	}
	if (rSell.Over(j))
	{
		if (trueOrNot == 0)
		{
			rSell.SetColor(sf::Color(110, 3, 3),sf::Color::Red); //podswietlony
			transactionAmount = 0;
			trueOrNot = 2;
		}
		else if(trueOrNot == 2)
		{
			trueOrNot = 0;
			rSell.SetColor(sf::Color(140, 3, 3),sf::Color::Red); //stary kolor
			if(transactionAmount>0)
			{
			for(int i=4; i>0 ;i--)
			{
				tHistory[i].setString(tHistory[i-1].getString());
			}
			tHistory[0].setString("Sold " + std::to_string(transactionAmount) + " assets for $" + Cut(std::to_string(price)) + " each.");
		}
			amount -= transactionAmount;
			wealth += price * transactionAmount;
		}
	}
	if (trueOrNot)
	{
		if (rectangles["+"].Over(j) and transactionAmount > 0)
		{
			transactionAmount -= 1;
		}
		if (rectangles["-"].Over(j) and (trueOrNot == 1 or transactionAmount < amount))
		{
			transactionAmount += 1;
		}
	}
}