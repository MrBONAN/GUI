#include "Button.h"

Button::Button(int width, int hight)
{
	dx = max(width, 4);
	dy = max(hight, 4);

	/*auto start = std::chrono::system_clock::now();*/
	RenderTex.create(dx, dy * 2);
	ImageRect TempImageRect(dx, dy, RenderTex, texture);
	/*auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> dir = end - start;
	cout << dir.count() << endl;*/

	texEnd = RenderTex.getTexture();
	button.setTexture(texEnd);

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

	RenderTex.create(dx, dy * 2);
	ImageRect TempImageRect(dx, dy, RenderTex, texture);

	texEnd = RenderTex.getTexture();
	button.setTexture(texEnd);

	Set_Sprite1();
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

//void Button::SetFunc(function<void(void)> EventBtn)
//{
//	this->EventBtn = EventBtn;
//	HaveFunc = true;
//}

void Button::Event(const sf::Vector2i& msCord)
{
	if (active && button.getGlobalBounds().contains(msCord.x, msCord.y))
	{
		isAlreadyUpdate = false;
		Set_Sprite1();
		UseFunc();
		if (HaveMutImage)
		{
			if (state)
			{
				image.setTextureRect(sf::IntRect(X1, Y1, constImageBtnDx, constImageBtnDy));
			}
			else
			{
				image.setTextureRect(sf::IntRect(X2, Y2, constImageBtnDx, constImageBtnDy));
			}
			state = !state;
		}
	}
	active = false;
}

void Button::CheckFocus(const sf::Vector2i& msCord)
{
	if ((mouseJustPressed || active ) && button.getGlobalBounds().contains(msCord.x, msCord.y)) {
		if (isAlreadyUpdate) return;
		isAlreadyUpdate = true;
		active = true;
		Set_Sprite2();
	} else if (active)
	{
		if (isAlreadyUpdate) {
			isAlreadyUpdate = false;
			Set_Sprite1();
		}
	}
}



void Button::SetImageBtn(int x, int y, int dx, int dy)
{
	HaveImage = true;
	ImageBtnDx = dx;
	ImageBtnDy = dy;
	image.setTexture(texture);
	image.setTextureRect(sf::IntRect(x, y, constImageBtnDx, constImageBtnDy));
	SetImagePos();
}

void Button::SetMutImageBtn(int X1, int Y1, int X2, int Y2, int dx, int dy)
{
	this->X1 = X1;
	this->Y1 = Y1;
	this->X2 = X2;
	this->Y2 = Y2;
	ImageBtnDx = dx;
	ImageBtnDy = dy;

	image.setTexture(texture);
	image.setTextureRect(sf::IntRect(X1, Y1, constImageBtnDx, constImageBtnDy));

	HaveImage = true;
	HaveMutImage = true;
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
