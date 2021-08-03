#ifndef _IMAGERECT_H_
#define _IMAGERECT_H_
#include <SFML/Graphics.hpp>
class ImageRect
{
public:
	ImageRect(int dx, int dy, sf::RenderTexture& RenderTex, sf::Texture& texture);
	ImageRect(int dx, int dy);
	void SetTemplCords(int X1, int Y1, int X2, int Y2, sf::RenderTexture& RenderTex, sf::Texture& texture);

	~ImageRect() {}
private:
	void SetTemplates1();
	void SetTemplates2();
	void SetRenderTexture(int y);

	sf::Sprite corner, top, LeftRight, LineUpDw, image, button;
	sf::RenderTexture* RenderTex;
	sf::Texture* texture;

	float dx = 45, dy = 15; // длина кнопки по умолчанию

	// размеры полей кнопки по умолчанию
	float lenTop = 41,     lenLR = 11,     lenCornerX = 2, lenCornerY = 2;
	// длина середины      длина левой    ширина и длина углов
	//                     и правой грани

	// константы 
	const int ImageDx = 15, ImageDy = 15; // размеры кнопки на рабочей текстуре
	const int ImageDxCorner = 2, ImageDyLR = 11, ImageDxTop = 11; // размеры полей кнопки 
	// координаты шаблона
	int X1 = 17, Y1 = 1; // координаты первого шаблона кнопки
	int X2 = 17, Y2 = 17; // координаты второго шаблона кнопки

};
#endif
