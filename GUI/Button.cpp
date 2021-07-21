#include "Button.h"

Button::Button(int width, int hight)
{
	dx = max(width, 4);
	dy = max(hight, 4);

	lenTop = dx - 2 * lenCornerX;
	lenLR = dy - 2 * lenCornerY;

	corner.setTexture(texture);
	top.setTexture(texture);
	LeftRight.setTexture(texture);

	top.scale(sf::Vector2f(lenTop / ImageDxTop, dy / ImageDy));
	LeftRight.scale(sf::Vector2f(1, lenLR / ImageDyLR));

	RenderTex.clear(sf::Color(0, 0, 0, 0));

	SetTemplates1();
	SetRenderTexture(0);
	SetTemplates2();
	SetRenderTexture(dy);
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

//void Button::SetDxDy(int dx, int dy)
//{
//	float xScale = dx / this->dx;
//	float yScale = dy / this->dy;
//	left.scale(sf::Vector2f(xScale, yScale));
//	top.scale(sf::Vector2f(xScale, yScale));
//	right.scale(sf::Vector2f(xScale, yScale));
//
//	if (xScale >= 1) {
//		top.setPosition(lenLR * xScale + top.getPosition().x, top.getPosition().y);
//		right.setPosition(lenLR * xScale + lenTop * xScale + right.getPosition().x, right.getPosition().y);
//	}
//	else {
//		top.setPosition( top.getPosition().x - lenLR * xScale, top.getPosition().y);
//		right.setPosition(right.getPosition().x - lenLR * xScale - lenTop * xScale, right.getPosition().y);
//	}
//	dx *= xScale;
//	dy *= yScale;
//
//	lenLR *= xScale;
//	lenTop *= xScale;
//
//	SetPos(left.getPosition().x, left.getPosition().y);
//}
//
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


void Button::SetTemplates1()
{
	corner.setTextureRect(sf::IntRect(X1, Y1, ImageDxCorner, ImageDxCorner));
	top.setTextureRect(sf::IntRect(X1 + ImageDxCorner, Y1, ImageDxTop, ImageDy));
	LeftRight.setTextureRect(sf::IntRect(X1, Y1 + ImageDxCorner, ImageDxCorner, ImageDy - 2 * ImageDxCorner));
}

void Button::SetTemplates2()
{
	corner.setTextureRect(sf::IntRect(X2, Y2, ImageDxCorner, ImageDxCorner));
	top.setTextureRect(sf::IntRect(X2 + ImageDxCorner, Y2, ImageDxTop, ImageDy));
	LeftRight.setTextureRect(sf::IntRect(X2, Y2 + ImageDxCorner, ImageDxCorner, ImageDy - 2 * ImageDxCorner));
}

void Button::SetRenderTexture(int y)
{

	corner.setPosition(sf::Vector2f(0, y));
	RenderTex.draw(corner);

	corner.rotate(90);

	corner.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, y));
	RenderTex.draw(corner);

	corner.rotate(90);

	corner.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, lenCornerY * 2 + lenLR + y));
	RenderTex.draw(corner);

	corner.rotate(90);

	corner.setPosition(sf::Vector2f(0, lenCornerY * 2 + lenLR + y));
	RenderTex.draw(corner);

	corner.rotate(90);

	top.setPosition(sf::Vector2f(lenCornerX, y));
	RenderTex.draw(top);

	LeftRight.setPosition(sf::Vector2f(0, lenCornerY + y));
	RenderTex.draw(LeftRight);

	LeftRight.rotate(180);

	LeftRight.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, lenCornerY + lenLR + y));
	RenderTex.draw(LeftRight);

	LeftRight.rotate(180);

	RenderTex.display();
}
