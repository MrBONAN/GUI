#ifndef _OBJ_H_
#define _OBJ_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using std::string;
using std::to_string;
using std::vector;
using std::max;

using std::cout;
using std::cin;
using std::endl;

class OBJ
{
public:
	static void Init(sf::RenderWindow& window, string TexPath = "Icons.png", int dxRenderTex = 0, int dyRenderTex = 0); //вызвать перед началом
	OBJ(); // конструктор по умолчанию
	
	virtual void SetPos(int x, int y) = 0; // сохранение позиции объекта
	virtual void SetDxDy(int dx, int dy) = 0; // сохранение размеров объекта
	virtual void SetScale(float scX, float scY) = 0; // сохранение размера объекта
	
	void SetWindow(sf::RenderWindow& window); // сохранение рабочего окна (по уполчанию оно у всех объектов одно)
	sf::RenderWindow& GetWindow(); // получение окна отрисовки объекта
	static void SetDef_Window(sf::RenderWindow& window); // сохранение рабочего окна дл€ всех наследников OBJ
	static sf::RenderWindow& GetDef_Window(); // получение окна по умолчанию дл€ всех наследников OBJ

	void SetTexture(string path); // сохранение рабочей текстуры (по умполчанию она у всех объектов одна)
	sf::Texture& GetTexture(); // рабоча€ текстура
	static void SetDef_Texture(string path); // изменение текстуры по умолчанию дл€ всех наследников OBJ
	static sf::Texture& GetDef_Texture(); // получение текстуры по умолчанию всех наследников OBJ

	virtual void Event(const sf::Vector2i& msCord) = 0; // метод проверки на взаимодействие
	static void CheckAllEvent(const sf::Vector2i& msCord); // метод проверки на взаимодействие всех наследников OBJ
	virtual void CheckFocus(const sf::Vector2i& msCord) = 0; // метод проверки на наведение (при нажатии лкм)
	static void CheckAllFocus(const sf::Vector2i& msCord); // метод провекри на наведение всех наследников OBJ

	virtual void Show() = 0; // метод отрисовки объекта
	static void ShowAll(); // метод отрисовки всех наследников OBJ

	static vector<OBJ*> allTypeObj; // вектор всех наследников OBJ
protected:
	sf::RenderWindow* window; 
	sf::Texture texture;
	static sf::RenderTexture RenderTex;
	sf::Texture texEnd;

	static sf::RenderWindow* DefWindow;
	static sf::Texture* DefTexture;
};

#endif