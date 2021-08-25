#include "Slider.h"

Slider::Slider(int lenght, int minValue, int maxValue) : dxLine(lenght), constDxLine(lenght), minValue(minValue), maxValue(maxValue)
{
	dxSlider = constDxSlider;
	dySlider = constDySlider;

	// создание линии
	RenderTex.create(dxLine, dyLine);
	{
		ImageRect TempImageRect(dxLine, dyLine);
		TempImageRect.SetTemplCords(X1, Y1, RenderTex, texture);
	}
	texEnd = RenderTex.getTexture();
	line.setTexture(texEnd);

	// создание slider
	RenderTex.create(dxSlider, dySlider * 2);
	ImageRect TempImageRect(dxSlider, dySlider, RenderTex, texture);
	texEndSlide = RenderTex.getTexture();
	slider.setTexture(texEndSlide);
	Set_Sprite1();

	value = (minValue + maxValue) / 2;
	sizeOneDivis = (dxLine - indent * 2 - dxSlider) / (maxValue - minValue);
	xSlider = dxSlider / 2;

	SetPos(0, 0);
}

void Slider::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
	line.setPosition(x, y);
	ySlider = y + (dyLine / 2) - dySlider / 2;
	xSlider = dxSlider / 2;
	slider.setPosition(x + indent + (value - minValue) * sizeOneDivis, ySlider);
}

void Slider::SetDxDy(int dx, int dy)
{

}

void Slider::SetScale(float scX, float scY)
{

	dxLine *= scX;
	dyLine *= scY;
	indent *= scX;
	dxSlider *= scX;
	dySlider *= scY;
	sizeOneDivis = (dxLine - indent * 2 - dxSlider) / (maxValue - minValue);

	scX *= line.getScale().x;
	scY *= line.getScale().y;
	line.setScale(scX, scY);
	slider.setScale(scX, scY);

	SetPos(line.getPosition().x, line.getPosition().y);
}

void Slider::Event(const sf::Vector2i& msCord)
{
	if (active)
	{
		Set_Sprite1();
		active = false;
	}
}

void Slider::SetValue(int val)
{
	value = max(min(val, maxValue), minValue);
	MoveSlider();
}

void Slider::AddValue(int addVal)
{
	value = max(min(value + addVal, maxValue), minValue);
	MoveSlider();
}


void Slider::CheckFocus(const sf::Vector2i& msCord)
{
	if (mouseJustPressed && slider.getGlobalBounds().contains(msCord.x, msCord.y))
	{
		active = true; // мы нажали именно на slider и начинаем его двигать до того, как отпустип ЛКМ
		Set_Sprite2();
	}
	if (active)
	{
		float msX = min(max(msCord.x - xSlider - x - indent, 0.f), (float)dxLine - indent * 2 - dxSlider);
		float temp = round(msX / sizeOneDivis);

		if (value != temp) {
			value = temp;
			MoveSlider();
		}
	}


}

void Slider::Show()
{
	window->draw(line);
	window->draw(slider);
}

void Slider::MoveSlider()
{
	slider.setPosition(x + indent + value * sizeOneDivis, ySlider);
	value += minValue;
	UseFunc();
}

void Slider::Set_Sprite1()
{
	slider.setTextureRect(sf::IntRect(0, 0, constDxSlider, constDySlider));
}

void Slider::Set_Sprite2()
{
	slider.setTextureRect(sf::IntRect(0, constDySlider, constDxSlider, constDySlider));
}
