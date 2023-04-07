#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 640), "Bird Game - Colin Enck");
    window.setFramerateLimit(60);

    sf::Texture backdrop;
    if (!backdrop.loadFromFile("background.png")) 
        return 1;
    sf::Sprite background; 
    background.setTexture(backdrop);
    background.setScale(sf::Vector2f(8.f, 8.f));

    sf::Texture bird1;
    if (!bird1.loadFromFile("bird1.png"))
        return 1;
    sf::Texture bird2;
    if (!bird2.loadFromFile("bird2.png"))
        return 1;
    sf::Sprite bird;
    bird.setTexture(bird1);
    bird.setScale(sf::Vector2f(8.f, 8.f));
    bird.setPosition(sf::Vector2f(267.f - 64, 213.f - 64));

    sf::Clock clock;
    sf::Time dt;

    float dv = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dt = clock.restart();
        dv -= dt.asMilliseconds();

        // keyboard inputs
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            dv += 3.125 * 19;

        bird.move(sf::Vector2f(0.f, -(dv * dt.asSeconds())));

        // drawing begins here
        window.clear();
        window.draw(background);
        window.draw(bird);
        window.display();
    }

    return 0;
}