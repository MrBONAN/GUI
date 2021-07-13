#include "Button.h"

Button::Button(int len)
{
	dx = max(len, 4);
	lenTop = dx - 4;

	left.setTexture(texture);
	top.setTexture(texture);
	right.setTexture(texture);

	Set_Sprite1();

	top.scale(sf::Vector2f(lenTop / ImageDxTop, 1));
	ImageDxTop *= lenTop / ImageDxTop;

	SetPos(0, 0);
}

void Button::SetPos(int x, int y)
{
	left.setPosition(sf::Vector2f(x, y));
	top.setPosition(sf::Vector2f(x + lenLR, y));
	right.setPosition(sf::Vector2f(x + lenLR + lenTop, y));
}

void Button::SetDxDy(int dx, int dy)
{
}

void Button::SetScale(float scX, float scY)
{
	left.scale(sf::Vector2f(scX, scY));
	top.scale(sf::Vector2f(scX, scY));
	right.scale(sf::Vector2f(scX, scY));
	dx *= scX;
	dy *= scY;

	lenLR *= scX;
	lenTop *= scX;

	SetPos(left.getPosition().x, left.getPosition().y);
}

void Button::Set_Sprite1()
{
	left.setTextureRect(sf::IntRect(X1, Y1, ImageDxLR, ImageDy));
	top.setTextureRect(sf::IntRect(X1 + ImageDxLR, Y1, ImageDxTop, ImageDy));
	right.setTextureRect(sf::IntRect(X1 + ImageDxLR + ImageDxTop, Y1, ImageDxLR, ImageDy));
}

void Button::Set_Sprite2()
{
	left.setTextureRect(sf::IntRect(X2, Y2, ImageDxLR, ImageDy));
	top.setTextureRect(sf::IntRect(X2 + ImageDxLR, Y2, ImageDxTop, ImageDy));
	right.setTextureRect(sf::IntRect(X2 + ImageDxLR + ImageDxTop, Y2, ImageDxLR, ImageDy));
}

void Button::Event(const sf::Vector2i& msCord)
{
	if (active)
	{
		active = !active;
		cout << "YES" << endl;
	}
}

void Button::CheckFocus(const sf::Vector2i& msCord)
{
	if (left.getGlobalBounds().contains(msCord.x, msCord.y)
		|| top.getGlobalBounds().contains(msCord.x, msCord.y)
		|| right.getGlobalBounds().contains(msCord.x, msCord.y)) {
		active = true;
		Set_Sprite2();
		std::cout << active << std::endl;
	}
	else if (active)
	{
		Set_Sprite1();
		active = !active;
	}
}

void Button::Show()
{
	window->draw(left);
	window->draw(top);
	window->draw(right);
}
