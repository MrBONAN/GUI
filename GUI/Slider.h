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
	// ������������� �� slider
	void MoveSlider();
	void Set_Sprite1();
	void Set_Sprite2();

	// ����������� ������������
	sf::Sprite slider; // ��������
	sf::Sprite line; // �����

	// ������� ���������� �����
	int x = 0, y = 0;
	double dxLine = 270; // ���������� ����� �����
	double constDxLine = 270; // ����� �����, ������� �� ����� ���������� � SetScale
	
	double dyLine = 11; // ���������� ������ �����
	const double constDyLine = 11; // ������ �����, ������� �� ����� ���������� � SetScale
	
	float indent = 6; // ������� � ����� � �����

	// ��������� slider
	float constDxSlider = 9, constDySlider = 15;
	float dxSlider, dySlider;
	float ySlider, xSlider;

	// ������ �����
	int X1 = 49, Y1 = 1; // ���������� ������� �����

	//�������� slider
	sf::Texture texEndSlide;

	// ����������
	int minValue, maxValue, value;
	double sizeOneDivis; // ������ � �������� ������ �������
	bool  active = false;
	
};

