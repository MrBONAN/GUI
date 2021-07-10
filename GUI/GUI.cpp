#include <iostream>
#include <SFML/Graphics.hpp>
#include "CheckBox.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "SFML works!");
    sf::Event event;

    window.setFramerateLimit(60);

    //Button btn(window, 10, 10, 90, 120);
    //btn.SetColor(sf::Color(100, 100, 100));

    sf::Texture texture;
    sf::Sprite sprite;

    string path = "Icons.png";

    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(1, 16, 15, 15));
    sprite.setScale(sf::Vector2f(10, 1));

    //OBJ::SetDef_Window(window);
    //OBJ::SetDef_Texture(path);

    CheckBox::Init(window, path);

    CheckBox btn;
    CheckBox bt;
    
    //btn.SetWindow(window);
    //btn.SetTexture(path);
    btn.SetPos(100, 100);
    btn.SetScale(10, 10);

    bt.SetPos(50, 50);
    bt.SetScale(2, 4);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.setTextureRect(sf::IntRect(1, 1, 15, 15));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.setTextureRect(sf::IntRect(1, 16, 15, 15));
        }

        //cout << endl << sf::Mouse::getPosition(window).x << '\t' << sf::Mouse::getPosition(window).y;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            
           /* int msX = sf::Mouse::getPosition().x - window.getPosition().x - 7;
            int msY = sf::Mouse::getPosition().y - window.getPosition().y;*/
            int msX = sf::Mouse::getPosition(window).x;
            int msY = sf::Mouse::getPosition(window).y;
            if (sprite.getGlobalBounds().contains(msX, msY)) cout << 1;
            /*cout << "\t\t" <<  window.mapPixelToCoords(sf::Mouse::getPosition(window)).x << '\t' << window.mapPixelToCoords(sf::Mouse::getPosition(window)).y << endl;
            
            btn.MousePres(msX, msY);*/
            
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            
            msPress = true;
        }
        else if (msPress){
            msPress = false;
            CheckBox::CheckAllEvent(sf::Mouse::getPosition(window));
        }

        window.clear();

        CheckBox::ShowAll();

        window.draw(sprite);
        window.display();
    }

    return 0;
}