#include "ImageRect.h"



ImageRect::ImageRect(int dx, int dy, sf::RenderTexture& RenderTex, sf::Texture& texture) : ImageRect::ImageRect(dx,dy)
{
	corner.setTexture(texture);
	top.setTexture(texture);
	LeftRight.setTexture(texture);
	LineUpDw.setTexture(texture);

	top.scale(sf::Vector2f(lenTop / ImageDxTop, (dy - lenCornerY * 2) / (ImageDy - ImageDxCorner * 2)));
	LeftRight.scale(sf::Vector2f(1, lenLR / ImageDyLR));
	LineUpDw.scale(sf::Vector2f(lenTop / ImageDxTop, 1));

	this->RenderTex = &RenderTex;

	RenderTex.clear(sf::Color(0, 0, 0, 0));

	SetTemplates1();
	SetRenderTexture(0);
	SetTemplates2();
	SetRenderTexture(dy);
}

ImageRect::ImageRect(int dx, int dy) : dx(dx), dy(dy) {
	lenTop = dx - 2 * lenCornerX;
	lenLR = dy - 2 * lenCornerY;
}

void ImageRect::SetTemplCords(int X1, int Y1, int X2, int Y2, sf::RenderTexture& RenderTex, sf::Texture& texture)
{
	this->X1 = X1;
	this->Y1 = Y1;
	this->X2 = X2;
	this->Y2 = Y2;

	corner.setTexture(texture);
	top.setTexture(texture);
	LeftRight.setTexture(texture);
	LineUpDw.setTexture(texture);

	top.scale(sf::Vector2f(lenTop / ImageDxTop, (dy - lenCornerY * 2) / (ImageDy - ImageDxCorner * 2)));
	LeftRight.scale(sf::Vector2f(1, lenLR / ImageDyLR));
	LineUpDw.scale(sf::Vector2f(lenTop / ImageDxTop, 1));

	this->RenderTex = &RenderTex;

	RenderTex.clear(sf::Color(0, 0, 0, 0));

	SetTemplates1();
	SetRenderTexture(0);
	SetTemplates2();
	SetRenderTexture(dy);
}

void ImageRect::SetTemplCords(int X1, int Y1, sf::RenderTexture& RenderTex, sf::Texture& texture)
{
	this->X1 = X1;
	this->Y1 = Y1;

	corner.setTexture(texture);
	top.setTexture(texture);
	LeftRight.setTexture(texture);
	LineUpDw.setTexture(texture);

	top.scale(sf::Vector2f(lenTop / ImageDxTop, (dy - lenCornerY * 2) / (ImageDy - ImageDxCorner * 2)));
	LeftRight.scale(sf::Vector2f(1, lenLR / ImageDyLR));
	LineUpDw.scale(sf::Vector2f(lenTop / ImageDxTop, 1));

	this->RenderTex = &RenderTex;

	RenderTex.clear(sf::Color(0, 0, 0, 0));

	SetTemplates1();
	SetRenderTexture(0);
}


// сделать через define func
void ImageRect::SetTemplates1()
{
	corner.setTextureRect(sf::IntRect(X1, Y1, ImageDxCorner, ImageDxCorner));
	top.setTextureRect(sf::IntRect(X1 + ImageDxCorner, Y1 + ImageDxCorner, ImageDxTop, ImageDy - ImageDxCorner * 2));
	LeftRight.setTextureRect(sf::IntRect(X1, Y1 + ImageDxCorner, ImageDxCorner, ImageDy - 2 * ImageDxCorner));
	LineUpDw.setTextureRect(sf::IntRect(X1 + ImageDxCorner, Y1, ImageDxTop, ImageDxCorner));
}

void ImageRect::SetTemplates2()
{
	corner.setTextureRect(sf::IntRect(X2, Y2, ImageDxCorner, ImageDxCorner));
	top.setTextureRect(sf::IntRect(X2 + ImageDxCorner, Y2 + ImageDxCorner, ImageDxTop, ImageDy - ImageDxCorner * 2));
	LeftRight.setTextureRect(sf::IntRect(X2, Y2 + ImageDxCorner, ImageDxCorner, ImageDy - 2 * ImageDxCorner));
	LineUpDw.setTextureRect(sf::IntRect(X2 + ImageDxCorner, Y2, ImageDxTop, ImageDxCorner));
}

void ImageRect::SetRenderTexture(int y)
{
	corner.setPosition(sf::Vector2f(0, y));
	RenderTex->draw(corner);
	corner.rotate(90);

	corner.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, y));
	RenderTex->draw(corner);
	corner.rotate(90);

	corner.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, lenCornerY * 2 + lenLR + y));
	RenderTex->draw(corner);
	corner.rotate(90);

	corner.setPosition(sf::Vector2f(0, lenCornerY * 2 + lenLR + y));
	RenderTex->draw(corner);
	corner.rotate(90);


	top.setPosition(sf::Vector2f(lenCornerX, y + lenCornerY));
	RenderTex->draw(top);


	LeftRight.setPosition(sf::Vector2f(0, lenCornerY + y));
	RenderTex->draw(LeftRight);
	LeftRight.rotate(180);

	LeftRight.setPosition(sf::Vector2f(lenCornerX * 2 + lenTop, lenCornerY + lenLR + y));
	RenderTex->draw(LeftRight);
	LeftRight.rotate(180);

	LineUpDw.setPosition(sf::Vector2f(lenCornerX, y));
	RenderTex->draw(LineUpDw);
	LineUpDw.rotate(180);

	LineUpDw.setPosition(sf::Vector2f(lenCornerX + lenTop, y + lenCornerY * 2 + lenLR));
	RenderTex->draw(LineUpDw);
	LineUpDw.rotate(180);

	RenderTex->display();
}
