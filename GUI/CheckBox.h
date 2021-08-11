#ifndef _CHECK_BOX_H_
#define _CHECK_BOX_H_

#include "OBJ.h"

class CheckBox : public OBJ
{
public:
	CheckBox();

	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override;
	void SetScale(float scX, float scY) override;

	void Set_Sprite1();
	void Set_Sprite2();

	void Event(const sf::Vector2i& msCord) override;
	void CheckFocus(const sf::Vector2i& msCord) override;
	void Show() override;

	void SetIMG_dxy(int dx = 15, int dy = 15);
	void SetIMG_xy1(int x = 1, int y = 1);
	void SetIMG_xy2(int x = 1, int y = 16);

private:
	bool active = false, state = false;
	sf::Sprite sprite;
	float dx = 15, dy = 15;
	int ImageDx = 15, ImageDy = 15;
	int X1 = 1, Y1 = 1;
	int X2 = 1, Y2 = 17;
};

#endif