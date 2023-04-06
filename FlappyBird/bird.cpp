#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");

    sf::Texture backdrop;
    if (!backdrop.loadFromFile("background.png")) 
        return 0;
    sf::Sprite background; 
    background.setTexture(backdrop);

    sf::RectangleShape bird(sf::Vector2f(20.f, 20.f));
    bird.setPosition(280, 380);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(bird);
        window.display();
    }

    return 0;
}
