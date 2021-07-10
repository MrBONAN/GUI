#include "OBJ.h"

sf::RenderWindow* OBJ::DefWindow = nullptr;
sf::Texture* OBJ::DefTexture = nullptr;
vector<OBJ*> OBJ::allTypeObj;

void OBJ::Init(sf::RenderWindow& window, string path)
{
	OBJ::DefWindow = &window;
	OBJ::DefTexture = new sf::Texture;
	OBJ::DefTexture->loadFromFile(path);
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

// метод общей отрисовки

void OBJ::ShowAll()
{
	for (auto obj : OBJ::allTypeObj)
	{
		obj->Show();
	}
}