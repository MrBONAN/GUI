#pragma once
#include "OBJ.h"
class TextRect : public OBJ
{
public:
	TextRect();
	void SetPos(int x, int y) override;
	void SetDxDy(int dx, int dy) override;
	void SetScale(float scX, float scY) override;

	void Event(const sf::Vector2i& msCord) override {};
	void CheckFocus(const sf::Vector2i& msCord) override {};

	void SetText(int data, string str, int dx, int dy);

	void SetText(int data, int dx, int dy);

	void SetRectColor(sf::Color color) { rect.setFillColor(color); }
	void SetOutlineColor(sf::Color color) { rect.setOutlineColor(color); }
	void SetOutlineThickness(float d) { rect.setOutlineThickness(d); }

	void SetString();

	void Show() override;

	~TextRect() {};
private:
	int x, y;
	int dx = 100, dy = 30;
	int size = 24;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape rect;
	string str = "Test ", data = "5";
};