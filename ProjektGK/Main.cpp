#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width - 800, desktop.height - 200), "Arkanoid");

    // Utw�rz platform�
    Platform platform(&window,150.0f, 20.0f, 0.1f);
    platform.setPosition(window.getSize().x / 2.0f, window.getSize().y);

    //Utw�rz pi�k� 
    Ball ball(10.0f, 0.1f,&window,&platform);
    ball.setPosition(window.getSize().x / 2.0f, window.getSize().y - platform.getHeight() * 1.5f - ball.getRadius());

    // G��wna p�tla gry
    while (window.isOpen())
    {
        // Sprawd� zdarzenia
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Poruszanie platform�
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            platform.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            platform.moveRight();
        }

        ball.update();
        // Wyczy�� ekran
        window.clear(sf::Color::Black);

        // Wy�wietl plansz�

        // Narysuj platform�
        platform.draw();
        ball.draw();

        // Zako�cz rysowanie
        window.display();
    }

    return 0;
}

   