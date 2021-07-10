#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "OBJ.h"

class Button : public OBJ
{
public:
	Button ();

	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override;
	void SetScale(float scX, float scY) override;

	void Set_Sprite1();
	void Set_Sprite2();

	void Event(const sf::Vector2i& msCord) override;
	void Show() override;

	~Button ();

private:
	sf::Sprite sprite;
	float dx = 15, dy = 15;
	bool active = false;
};
#endif