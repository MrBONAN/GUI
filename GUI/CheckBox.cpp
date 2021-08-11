#include "CheckBox.h"

CheckBox::CheckBox(int width, int hight)
{
	checkBox.SetMutImageBtn(1, 1, 1, 17, 15, 15);
	checkBox.SetDxDy(width, hight);
}

void CheckBox::SetPos(int x, int y)
{
	checkBox.SetPos(x, y);
}

void CheckBox::SetDxDy(int dx, int dy)
{
	checkBox.SetDxDy(dx, dy);
}

void CheckBox::SetScale(float scX, float scY)
{
	checkBox.SetScale(scX, scY);
}

void CheckBox::Show()
{
	checkBox.Show();
}