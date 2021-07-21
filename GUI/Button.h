#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "OBJ.h"

class Button : public OBJ
{
public:
	Button (int width = 45, int hight = 15);

	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override {};
	void SetScale(float scX, float scY) override;

	void Set_Sprite1();
	void Set_Sprite2();

	void SetFunc(void (*EventBtn)());
	void Event(const sf::Vector2i& msCord) override;
	void CheckFocus(const sf::Vector2i& msCord) override;

	void SetImageBtn(int x = 33, int y = 17, int dx = 15, int dy = 15);
	void SetImageScale(float scX, float scY);
	void SetImagePos();

	void Show() override;

	~Button() {};

	bool active = false;
private:
	void SetTemplates1();
	void SetTemplates2();
	void SetRenderTexture(int y);

	sf::Sprite corner, top, LeftRight, LineUpDw, image, button;
	float ImageBtnDx = 15, ImageBtnDy = 15;
	bool HaveImage = false;

	float dx = 45, dy = 15; // ����� ������ �� ���������
	float lenTop = 41, lenLR = 11, lenCornerX = 2, lenCornerY = 2;

	// �� ���� ��������� (����� ������� �� �����������)
	int ImageDx = 15, ImageDy = 15; // ������� ������ �� ������� ��������
	int ImageDxCorner = 2, ImageDyLR = 11, ImageDxTop = 11; // ������� ����� ������ 
	int X1 = 17, Y1 = 1; // ���������� ������� ������� ������
	int X2 = 17, Y2 = 17; // ���������� ������� ������� ������

	bool HaveFunc = false;
	void (*EventBtn)();
};
#endif