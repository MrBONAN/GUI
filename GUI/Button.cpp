#include "Button.h"

Button::Button(int width, int hight)
{
	dx = max(width, 4);
	dy = max(hight, 4);

	//auto start = std::chrono::system_clock::now();
	ImageRect TempImageRect(dx, dy, RenderTex, texture);
	//auto end = std::chrono::system_clock::now();
	//std::chrono::duration<double> dir = end - start;
	//cout << dir.count() << endl;

	texEnd = RenderTex.getTexture();
	button.setTexture(texEnd);
	button.setTextureRect(sf::IntRect(0, 0, dx, dy));

	Set_Sprite1();

	SetPos(0, 0);
}

void Button::SetPos(int x, int y)
{
	button.setPosition(x, y);
	if (HaveImage) SetImagePos();
}

void Button::SetDxDy(int dx, int dy)
{
	this->dx = dx;
	this->dy = dy;

	ImageRect TempImageRect(dx, dy, RenderTex, texture);

}

void Button::SetScale(float scX, float scY)
{
	if (HaveImage) SetImageScale(scX, scY);
	scX *= button.getScale().x;
	scY *= button.getScale().y;
	button.setScale(scX, scY);
	SetImagePos();
}

void Button::Set_Sprite1()
{
	button.setTextureRect(sf::IntRect(0, 0, dx, dy));
}

void Button::Set_Sprite2()
{
	button.setTextureRect(sf::IntRect(0, dy, dx, dy));
}

void Button::SetFunc(void(*EventBtn)())
{
	this->EventBtn = EventBtn;
	HaveFunc = true;
}

void Button::Event(const sf::Vector2i& msCord)
{
	if (active)
	{
		Set_Sprite1();
		active = !active;
		if (HaveFunc) EventBtn();
	}
}


void Button::CheckFocus(const sf::Vector2i& msCord)
{
	if (button.getGlobalBounds().contains(msCord.x, msCord.y)) {
		if (active) return;
		active = true;
		Set_Sprite2();
	}
	else if (active)
	{
		Set_Sprite1();
		active = false;
	}
}



void Button::SetImageBtn(int x, int y, int dx, int dy)
{
	HaveImage = true;
	image.setTexture(texture);
	image.setTextureRect(sf::IntRect(x, y, dx, dy));
	SetImagePos();
}

void Button::SetImageScale(float scX, float scY)
{
	ImageBtnDx *= scX;
	ImageBtnDy *= scY;
	scX *= image.getScale().x;
	scY *= image.getScale().y;
	image.setScale(scX, scY);
	SetImagePos();
}

void Button::SetImagePos()
{
	image.setPosition(button.getPosition().x + (dx * button.getScale().x - ImageBtnDx) / 2,
		button.getPosition().y + (dy * button.getScale().y - ImageBtnDy) / 2);
}



void Button::Show()
{
	window->draw(button);
	if (HaveImage) window->draw(image);
}
