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

	void SetTextString(string str);
	void SetTextData(int data);
	void SetFont(string font);

	void SetRectColor(sf::Color color) { rect.setFillColor(color); }
	void SetOutlineColor(sf::Color color) { rect.setOutlineColor(color); }
	void SetOutlineThickness(float d) { rect.setOutlineThickness(d); }

	void Show() override;

	~TextRect() {};

	sf::Text text;
private:
	int x, y;
	int dx = 100, dy = 30;
	sf::Font font;
	//sf::Text::Style style = sf::Text::Style::Regular;
	//sf::Color color = sf::Color::Black;

	sf::RectangleShape rect;
	string str = "None", data = "";
};