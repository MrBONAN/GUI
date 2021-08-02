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
	static void Init(sf::RenderWindow& window, string TexPath = "Icons.png", int dxRenderTex = 0, int dyRenderTex = 0); //������� ����� �������
	OBJ(); // ����������� �� ���������
	
	virtual void SetPos(int x, int y) = 0; // ���������� ������� �������
	virtual void SetDxDy(int dx, int dy) = 0; // ���������� �������� �������
	virtual void SetScale(float scX, float scY) = 0; // ���������� ������� �������
	
	void SetWindow(sf::RenderWindow& window); // ���������� �������� ���� (�� ��������� ��� � ���� �������� ����)
	sf::RenderWindow& GetWindow(); // ��������� ���� ��������� �������
	static void SetDef_Window(sf::RenderWindow& window); // ���������� �������� ���� ��� ���� ����������� OBJ
	static sf::RenderWindow& GetDef_Window(); // ��������� ���� �� ��������� ��� ���� ����������� OBJ

	void SetTexture(string path); // ���������� ������� �������� (�� ���������� ��� � ���� �������� ����)
	sf::Texture& GetTexture(); // ������� ��������
	static void SetDef_Texture(string path); // ��������� �������� �� ��������� ��� ���� ����������� OBJ
	static sf::Texture& GetDef_Texture(); // ��������� �������� �� ��������� ���� ����������� OBJ

	virtual void Event(const sf::Vector2i& msCord) = 0; // ����� �������� �� ��������������
	static void CheckAllEvent(const sf::Vector2i& msCord); // ����� �������� �� �������������� ���� ����������� OBJ
	virtual void CheckFocus(const sf::Vector2i& msCord) = 0; // ����� �������� �� ��������� (��� ������� ���)
	static void CheckAllFocus(const sf::Vector2i& msCord); // ����� �������� �� ��������� ���� ����������� OBJ

	virtual void Show() = 0; // ����� ��������� �������
	static void ShowAll(); // ����� ��������� ���� ����������� OBJ

	static vector<OBJ*> allTypeObj; // ������ ���� ����������� OBJ
protected:
	sf::RenderWindow* window; 
	sf::Texture texture;
	static sf::RenderTexture RenderTex;
	sf::Texture texEnd;

	static sf::RenderWindow* DefWindow;
	static sf::Texture* DefTexture;
};

#endif