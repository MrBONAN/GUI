#include <iostream>
#include <SFML/Graphics.hpp>
#include "CheckBox.h"
#include "Button.h"
#include "TextRect.h"

void print()
{
    cout << "It's work!" << endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "SFML works!");
    sf::Event event;

    window.setFramerateLimit(60);

    string path = "Icons.png";

    OBJ::Init(window, path);

    CheckBox CHCKbtn;

    CHCKbtn.SetPos(50, 50);
    CHCKbtn.SetScale(4, 4);

    Button btn(15);
    btn.SetPos(200, 200);
    btn.SetScale(2, 2);
    btn.SetFunc(print);
    btn.SetBtnImage();
    btn.SetImageScale(2, 2);
    
    TextRect rct;

    rct.SetDxDy(100, 60);
    rct.SetPos(300, 100);
    rct.SetScale(5, 5);
    rct.SetString();

    bool msPress = false;

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

        window.display();
    }

    return 0;
}