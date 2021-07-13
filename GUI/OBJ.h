#ifndef _OBJ_H_
#define _OBJ_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::max;

using std::cout;
using std::cin;
using std::endl;

class OBJ
{
public:
	static void Init(sf::RenderWindow& window, string path = "Icons.png"); //вызвать перед началом
	OBJ(); // конструктор по умолчанию
	
	virtual void SetPos(int x, int y) = 0; // сохранение позиции объекта
	virtual void SetDxDy(int dx, int dy) = 0; // сохранение размеров объекта
	virtual void SetScale(float scX, float scY) = 0; // сохранение размера объекта
	
	void SetWindow(sf::RenderWindow& window); // сохранение рабочего окна (по уполчанию оно у всех объектов одно)
	sf::RenderWindow& GetWindow();
	static void SetDef_Window(sf::RenderWindow& window); // сохранение рабочего окна для всех новых последующих объектов
	static sf::RenderWindow& GetDef_Window();

	void SetTexture(string path); // сохранение рабочей текстуры (по умполчанию она у всех объектов одна)
	sf::Texture& GetTexture();
	static void SetDef_Texture(string path); // изменение рабочей текстуры для всех новых последующих объектов
	static sf::Texture& GetDef_Texture();

	virtual void Event(const sf::Vector2i& msCord) = 0; // метод проверки на взаимодействие
	static void CheckAllEvent(const sf::Vector2i& msCord);
	virtual void CheckFocus(const sf::Vector2i& msCord) = 0;
	static void CheckAllFocus(const sf::Vector2i& msCord);

	virtual void Show() = 0; // Метод отрисовки объекта
	static void ShowAll();

	static vector<OBJ*> allTypeObj;
protected:
	sf::RenderWindow* window;
	sf::Texture texture;

	static sf::RenderWindow* DefWindow;
	static sf::Texture* DefTexture;
};

#endif