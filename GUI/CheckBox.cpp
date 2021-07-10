#include "CheckBox.h"

CheckBox::CheckBox()
{
	this->sprite.setTexture(this->texture);

	Set_Sprite1();
	//Set_Sprite2();
}

void CheckBox::SetPos(int x, int y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

void CheckBox::SetDxDy(int dx, int dy)
{
	this->sprite.scale(sf::Vector2f(dx / this->dx, dy / this->dy));
	this->dx = dx;
	this->dy = dy;
}

void CheckBox::SetScale(float scX, float scY)
{
	this->sprite.scale(sf::Vector2f(scX, scY));
	this->dx *= scX;
	this->dy *= scY;
}

void CheckBox::Set_Sprite1()
{
	this->sprite.setTextureRect(sf::IntRect(1, 1, 15, 15)); // переделать на изменяемые координаты
}

void CheckBox::Set_Sprite2()
{
	this->sprite.setTextureRect(sf::IntRect(1, 16, 15, 15)); // переделать на изменяемые координаты
}

void CheckBox::Event(const sf::Vector2i& msCord)
{
	//std::cout << '\t' << this->sprite.getPosition().x << '\t' << this->sprite.getPosition().y << std::endl;
	if (this->sprite.getGlobalBounds().contains(msCord.x, msCord.y)) {
		if (this->active == false)
		{
			Set_Sprite2();
			this->active = true;
		}
		else {
			Set_Sprite1();
			this->active = false;
		}
		std::cout << this->active << std::endl;
	}
}

void CheckBox::Show()
{
	this->window->draw(this->sprite);
}