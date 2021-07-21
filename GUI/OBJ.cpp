#include "OBJ.h"

sf::RenderWindow* OBJ::DefWindow = nullptr;
sf::Texture* OBJ::DefTexture = nullptr;
sf::RenderTexture OBJ::RenderTex;
vector<OBJ*> OBJ::allTypeObj;

void OBJ::Init(sf::RenderWindow& window, string TexPath, int dxRenderTex, int dyRenderTex)
{
	OBJ::DefWindow = &window;
	OBJ::DefTexture = new sf::Texture;
	OBJ::DefTexture->loadFromFile(TexPath);
	if (dxRenderTex > 0 && dyRenderTex > 0)
	{
		OBJ::RenderTex.create(dxRenderTex, dyRenderTex);
	}
	else
	{
		OBJ::RenderTex.create(window.getSize().x, window.getSize().y);
	}
}
OBJ::OBJ()
{
	this->window = OBJ::DefWindow;
	this->texture = *OBJ::DefTexture;
	OBJ::allTypeObj.push_back(this);
}

//методы окна 
void OBJ::SetWindow(sf::RenderWindow& window)
{
	this->window = &window;
}

sf::RenderWindow& OBJ::GetWindow()
{
	return *this->window;
}

void OBJ::SetDef_Window(sf::RenderWindow& window)
{
	OBJ::DefWindow = &window;
}

sf::RenderWindow& OBJ::GetDef_Window()
{
	return *OBJ::DefWindow;
}


// методы текстуры
void OBJ::SetTexture(string path)
{
	this->texture.loadFromFile(path);
}

sf::Texture& OBJ::GetTexture()
{
	return this->texture;
}

void OBJ::SetDef_Texture(string path)
{
	OBJ::DefTexture->loadFromFile(path);
}

sf::Texture& OBJ::GetDef_Texture()
{
	return *OBJ::DefTexture;
}

// метод общей проверки на нажатие

void OBJ::CheckAllEvent(const sf::Vector2i& msCord)
{
	for (auto obj : OBJ::allTypeObj)
	{
		obj->Event(msCord);
	}
}

void OBJ::CheckAllFocus(const sf::Vector2i& msCord)
{
	for (auto it : allTypeObj)
	{
		it->CheckFocus(msCord);
	}
}

// метод общей отрисовки

void OBJ::ShowAll()
{
	for (auto obj : OBJ::allTypeObj)
	{
		obj->Show();
	}
}