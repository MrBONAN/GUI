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

	void Event(const sf::Vector2i& msCord) override;

	void CheckFocus(const sf::Vector2i& msCord) override;
	
	void SetImageBtn(int x = 33, int y = 17, int dx = 15, int dy = 15);
	void SetMutImageBtn(int X1 = 33, int Y1 = 1, int X2 = 33, int Y2 = 17, int dx = 15, int dy = 15);
	void SetImageScale(float scX, float scY);
	void SetImagePos();

	void Show() override;

	~Button() {};
private:
	bool active = false;          // если на кнопку нажали в первый тик, то она активируется
	bool state = false;           //  состояние активации кнопки (для изменчивых изображений)
	bool isAlreadyUpdate = false; // для проверки на то, отрисовали ли мы уже текущую картинку кнопки
	// сделать в будущем проверку: если мы уже активировали объект (любой),
	// то не проверять остальные объекты + можно сделать так, чтобы в последующих
	// проверках фокуса мы проверяли только тот единственный объект (для оптимизации)


	sf::Sprite image, button;

	float ImageBtnDx = 15, ImageBtnDy = 15;
	float constImageBtnDx = 15, constImageBtnDy = 15;
	bool HaveImage = false;
	
	bool HaveMutImage = false;
	int X1, Y1, X2, Y2;

	float dx = 45, dy = 15; // длина кнопки по умолчанию

	//void (*EventBtn)();
	//function<void(void)> EventBtn;
};
#endif