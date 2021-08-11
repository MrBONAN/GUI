#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "OBJ.h"
#include "ImageRect.h"
#include <functional>

using std::function;

class Button : public OBJ
{
public:
	Button (int width = 45, int hight = 15);

	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override;
	void SetScale(float scX, float scY) override;

	void Set_Sprite1();
	void Set_Sprite2();

	void SetFunc(function<void(void)> EventBtn);
	void Event(const sf::Vector2i& msCord) override;

	void CheckFocus(const sf::Vector2i& msCord) override;
	
	void SetImageBtn(int x = 33, int y = 17, int dx = 15, int dy = 15);
	void SetMutImageBtn(int X1 = 33, int Y1 = 1, int X2 = 33, int Y2 = 17, int dx = 15, int dy = 15);
	void SetImageScale(float scX, float scY);
	void SetImagePos();

	void Show() override;

	~Button() {};
private:
	bool active = false, state = false;

	sf::Sprite image, button;

	float ImageBtnDx = 15, ImageBtnDy = 15;
	float constImageBtnDx = 15, constImageBtnDy = 15;
	bool HaveImage = false;
	
	bool HaveMutImage = false;
	int X1, Y1, X2, Y2;

	float dx = 45, dy = 15; // ����� ������ �� ���������

	bool HaveFunc = false;
	//void (*EventBtn)();
	function<void(void)> EventBtn;
};
#endif