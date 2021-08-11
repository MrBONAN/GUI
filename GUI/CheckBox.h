#ifndef _CHECK_BOX_H_
#define _CHECK_BOX_H_

#include "Button.h"

class CheckBox
{
public:
	CheckBox(int width = 15, int hight = 15);

	void SetPos(int x, int y);
	void SetDxDy(int dx, int dy);
	void SetScale(float scX, float scY);

	void Show();

private:
	Button checkBox;
};

#endif