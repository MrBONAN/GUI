#include "OBJ.h"

sf::Vector2i OBJ::PastMsCord = sf::Vector2i(0, 0);
bool OBJ::mouseJustPressed = true;

sf::RenderWindow* OBJ::DefWindow = nullptr;
sf::Texture* OBJ::DefTexture = nullptr;
sf::RenderTexture OBJ::RenderTex;
vector<OBJ*> OBJ::allTypeObj;

void OBJ::Init(sf::RenderWindow& window, string TexPath)
{
	OBJ::DefWindow = &window;
	OBJ::DefTexture = new sf::Texture;
	OBJ::DefTexture->loadFromFile(TexPath);
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
	mouseJustPressed = true;
}

void OBJ::CheckAllFocus(const sf::Vector2i& msCord)
{
	if (mouseJustPressed || msCord != PastMsCord)
	{
		cout << "CHECKFOCUS" << endl;
		PastMsCord = msCord;
		for (auto it : allTypeObj)
		{
			it->CheckFocus(msCord);
		}
		mouseJustPressed = false;
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