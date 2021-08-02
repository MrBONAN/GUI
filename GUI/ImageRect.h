#ifndef _IMAGERECT_H_
#define _IMAGERECT_H_
#include <SFML/Graphics.hpp>
class ImageRect
{
public:
	ImageRect(int width, int hight, sf::RenderTexture& RenderTex, sf::Texture& texture);
	~ImageRect() {}
private:
	void SetTemplates1();
	void SetTemplates2();
	void SetRenderTexture(int y);

	sf::Sprite corner, top, LeftRight, LineUpDw, image, button;
	sf::RenderTexture* RenderTex;
	sf::Texture* texture;

	float dx = 45, dy = 15; // ����� ������ �� ���������

	// ������� ����� ������ �� ���������
	float lenTop = 41,     lenLR = 11,     lenCornerX = 2, lenCornerY = 2;
	// ����� ��������      ����� ������    ������ � ����� �����
	//                     � ������� ����

	// ��������� 
	const int ImageDx = 15, ImageDy = 15; // ������� ������ �� ������� ��������
	const int ImageDxCorner = 2, ImageDyLR = 11, ImageDxTop = 11; // ������� ����� ������ 
	const int X1 = 17, Y1 = 1; // ���������� ������� ������� ������
	const int X2 = 17, Y2 = 17; // ���������� ������� ������� ������

};
#endif
