#ifndef _CHECK_BOX_H_
#define _CHECK_BOX_H_

//#include <SFML/Graphics.hpp>
//#include <iostream>

#include "OBJ.h" // все нужные библиотеки уже подключены

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
	void Show() override;
private:
	sf::Sprite sprite;
	float dx = 15, dy = 15;
	bool active = false;
};

#endif