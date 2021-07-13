#include "CheckBox.h"

CheckBox::CheckBox()
{
	sprite.setTexture(texture);

	Set_Sprite1();
	//Set_Sprite2();
}

void CheckBox::SetPos(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}

void CheckBox::SetDxDy(int dx, int dy)
{
	sprite.scale(sf::Vector2f(dx / this->dx, dy / this->dy));
	this->dx = dx;
	this->dy = dy;
}

void CheckBox::SetScale(float scX, float scY)
{
	sprite.scale(sf::Vector2f(scX, scY));
	dx *= scX;
	dy *= scY;
}

void CheckBox::Set_Sprite1()
{
	sprite.setTextureRect(sf::IntRect(X1, Y1, ImageDx, ImageDy));
}

void CheckBox::Set_Sprite2()
{
	sprite.setTextureRect(sf::IntRect(X2, Y2, ImageDx, ImageDy));
}

void CheckBox::Event(const sf::Vector2i& msCord)
{
	//std::cout << '\t' << this->sprite.getPosition().x << '\t' << this->sprite.getPosition().y << std::endl;
	if (sprite.getGlobalBounds().contains(msCord.x, msCord.y)) {
		active = !this->active;
		if (active == true)
		{
			Set_Sprite2();
		}
		else {
			Set_Sprite1();
		}
		std::cout << active << std::endl;
	}
}

void CheckBox::Show()
{
	this->window->draw(sprite);
}

void CheckBox::SetIMG_dxy(int dx, int dy) {
	ImageDx = dx;
	ImageDy = dy;
}

void CheckBox::SetIMG_xy1(int x, int y)
{
	X1 = x;
	Y1 = y;
}

void CheckBox::SetIMG_xy2(int x, int y)
{
	X2 = x;
	Y2 = y;
}