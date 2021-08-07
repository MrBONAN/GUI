#include "GUI.h"

using namespace sf;

void print()
{
    cout << "It's work!" << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    sf::RenderWindow window(sf::VideoMode(800, 450),  L"Работает?" );
    sf::Event event;
        
    window.setFramerateLimit(60);

    string path = "icons.png";

    OBJ::Init(window, path);

    CheckBox CHCKbtn;

    CHCKbtn.SetPos(20, 20);
    CHCKbtn.SetScale(4, 4);

    Button btn (15, 15);
    //btn.SetScale(4, 4);
    btn.SetFunc(print);
    btn.SetMutImageBtn();
    //btn.SetImageScale(2, 2);
    btn.SetScale(4, 4);
    btn.SetPos(300, 0);
    
    TextRect rct;

    //rct.SetDxDy(100, 60);
    rct.SetPos(300, 100);
    //rct.text.setCharacterSize(48);
    rct.SetTextString("English? WHY: ");
    rct.SetTextData(10);
    rct.SetDxDy(300, 30);

    Slider sl(270, -100, 100);
    sl.SetPos(100, 400);
    sl.SetScale(2, 2);
    //sl.SetScale(0.5, 0.5);

    /*sf::RenderTexture rt;
    rt.create(10, 10);

    Sprite sp;
    Texture tx;
    tx.loadFromFile("Icons.png");
    sp.setTexture(tx);*/

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
        rct.SetTextData(sl.GetValue());
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