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

	rect.setFillColor(sf::Color(77, 77, 77));
	rect.setSize(sf::Vector2f(dx, dy));
}

void TextRect::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
	rect.setPosition(sf::Vector2f(x, y));
	text.setPosition(sf::Vector2f(x + 5, y + 5));
}

void TextRect::Show()
{
	window->draw(rect);
	window->draw(text);
}
