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

	float dx = 45, dy = 15; // ����� ������ �� ���������

	// ������� ����� ������ �� ���������
	float lenTop = 41,     lenLR = 11,     lenCornerX = 2, lenCornerY = 2;
	// ����� ��������      ����� �����    ������ � ����� �����
	//                     � ������ �����

	// ��������� 
	const int ImageDx = 15, ImageDy = 15; // ������� ������ �� ������� ��������
	const int ImageDxCorner = 2, ImageDyLR = 11, ImageDxTop = 11; // ������� ����� ������ 
	// ���������� �������
	int X1 = 17, Y1 = 1; // ���������� ������� ������� ������
	int X2 = 17, Y2 = 17; // ���������� ������� ������� ������

};
#endif
