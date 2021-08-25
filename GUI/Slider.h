#pragma once
#include "OBJ.h"
#include "ImageRect.h"
using std::min;
using std::round;

class Slider : public OBJ
{
public:
	Slider(int lenght = 270, int minValue = 0, int maxValue = 100);

	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override;
	void SetScale(float scX, float scY) override;

	void Event(const sf::Vector2i& msCord) override;
	int GetValue() { return value; }
	void SetValue(int val);
	void AddValue(int addVal);

	void CheckFocus(const sf::Vector2i& msCord) override;

	void Show() override;
private:
	// взаимодейсвие со slider
	void MoveSlider();
	void Set_Sprite1();
	void Set_Sprite2();

	// графические составляющие
	sf::Sprite slider; // ползунок
	sf::Sprite line; // линия

	// размеры параметров линии
	int x = 0, y = 0;
	double dxLine = 270; // изменяемая длина линии
	double constDxLine = 270; // длина линии, которая не будет изменяться в SetScale
	
	double dyLine = 11; // изменяемая ширина линии
	const double constDyLine = 11; // ширина линии, которая не будет изменяться в SetScale
	
	float indent = 6; // отступы с боков у линии

	// параметры slider
	float constDxSlider = 9, constDySlider = 15;
	float dxSlider, dySlider;
	float ySlider, xSlider;

	// шаблон линии
	int X1 = 49, Y1 = 1; // координаты шаблона линии

	//текстура slider
	sf::Texture texEndSlide;

	// переменные
	int minValue, maxValue, value;
	double sizeOneDivis; // размер в пикселях одного деления
	bool  active = false;
	
};

