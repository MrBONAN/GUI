#include "TextRect.h"

inline void TextRect::SetText(int data, string str, int dx, int dy)
{
	this->str = str;
	this->data = to_string(data);
	this->dx = dx;
	this->dy = dy;
	SetString();
}

inline void TextRect::SetText(int data, int dx, int dy)
{
	this->data = data;
	this->dx = dx;
	this->dy = dy;
	SetString();
}

void TextRect::SetString()
{
	text.setFont(font);
	text.setString(str + data);
	text.setCharacterSize(size);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
}

TextRect::TextRect()
{
	font.loadFromFile("arial.ttf");
	rect.setSize(sf::Vector2f(dx, dy));
	rect.setFillColor(sf::Color(170, 170, 170, 255));
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color(50, 50, 50, 255));
}

void TextRect::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
	rect.setPosition(sf::Vector2f(x, y));
	text.setPosition(sf::Vector2f(x + 5, y + 5));
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

void TextRect::Show()
{
	window->draw(rect);
	window->draw(text);
}
