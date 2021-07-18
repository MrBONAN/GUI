#include "TextRect.h"

TextRect::TextRect()
{
	font.loadFromFile("arial.ttf");
	rect.setSize(sf::Vector2f(dx, dy));
	rect.setFillColor(sf::Color(170, 170, 170, 255));
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color(50, 50, 50, 255));

	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Style::Regular);
	text.setFillColor(sf::Color::Black);
}

void TextRect::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
	rect.setPosition(sf::Vector2f(x, y));
	text.setPosition(sf::Vector2f(x + 5, y));
}

void TextRect::SetDxDy(int dx, int dy)
{
	this->dx = dx;
	this->dy = dy;
	rect.setSize(sf::Vector2f(dx, dy));
}

void TextRect::SetScale(float scX, float scY)
{
	dx *= scX;
	dy *= scY;
	rect.setScale(scX, scY);
}

void TextRect::SetTextString(string str)
{
	this->str = str;
	text.setString(this->str + data);
}

void TextRect::SetTextData(int data)
{
	this->data = to_string(data);
	text.setString(str + this->data);
}

void TextRect::SetFont(string font)
{
	this->font.loadFromFile(font);
	text.setFont(this->font);
}

void TextRect::Show()
{
	window->draw(rect);
	window->draw(text);
}
