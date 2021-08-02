#include <iostream>
#include <SFML/Graphics.hpp>
#include "CheckBox.h"
#include "Button.h"
#include "TextRect.h"

using namespace sf;

void print()
{
    cout << "It's work!" << endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "SFML works!");
    sf::Event event;
        
    window.setFramerateLimit(60);

    string path = "icons.png";

    OBJ::Init(window, path, 500, 500);

    CheckBox CHCKbtn;

    CHCKbtn.SetPos(20, 20);
    CHCKbtn.SetScale(4, 4);

    Button btn(30, 30);
    btn.SetScale(4, 4);
    btn.SetFunc(print);
    //btn.SetImageBtn();
    //btn.SetImageScale(2, 2);
    btn.SetScale(2, 2);
    btn.SetPos(300, 0);
    
    TextRect rct;

    //rct.SetDxDy(100, 60);
    rct.SetPos(300, 100);
    //rct.text.setCharacterSize(48);
    rct.SetTextString("Test: ");
    rct.SetTextData(10);

    sf::RenderTexture rt;
    rt.create(10, 10);

    Sprite sp;
    Texture tx;
    tx.loadFromFile("Icons.png");
    sp.setTexture(tx);

    bool msPress = false;
    int l;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                std::cout << event.key.code << std::endl;
            if (event.type == sf::Event::KeyReleased)
                std::cout << event.key.code << std::endl;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            msPress = true;
            OBJ::CheckAllFocus(sf::Mouse::getPosition(window));
        }
        else if (msPress){
            msPress = false;
            OBJ::CheckAllEvent(sf::Mouse::getPosition(window));
        }

        window.clear();

        OBJ::ShowAll();

       /* sp.setPosition({ 0, 0 });
        window.draw(sp);
        sp.rotate(180);
        sp.setPosition({ 100, 200 });
        window.draw(sp);
        sp.rotate(180);*/

        window.display();
    }

    return 0;
}