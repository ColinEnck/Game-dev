#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

// GUIDE FOR PIPES PORPORTIONS
//  7        7
// --> pipe <--
//      |
//      |28
//      |
//      V
// --> pipe <--
// 
// pipes are 66px long scaled to 528px
// 28px space between them scaled to 224px
// drawing is 25x160 px scaled to 200x1280 px

// bird is 16x16 (with 3px and 1px padding for x and y) scaled to 128x128 px

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 640), "Bird Game - Colin Enck");
    window.setFramerateLimit(60);

    sf::Texture backdrop;
    if (!backdrop.loadFromFile("background.png")) 
        return 1;
    sf::Sprite background; 
    background.setTexture(backdrop);
    background.setScale(sf::Vector2f(8.f, 8.f));

    sf::Texture birdTex;
    if (!birdTex.loadFromFile("bird.png"))
        return 1;
    sf::Sprite bird;
    bird.setTexture(birdTex);
    bird.setScale(sf::Vector2f(8.f, 8.f));
    bird.setPosition(sf::Vector2f(203.f, 149.f));

    sf::Texture pipesTex;
    if (!pipesTex.loadFromFile("pipes.png"))
        return 1;
    sf::Sprite pipes;
    pipes.setTexture(pipesTex);
    pipes.setScale(sf::Vector2f(8.f, 8.f));
    pipes.setPosition(sf::Vector2f(600.f, -325.f));

    sf::Clock clock;
    sf::Time dt;

    float velocity = 0;

    bool inTubeX;
    bool touchTube;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        srand(time(NULL));

        // clock stuff
        dt = clock.restart();
        velocity -= dt.asMilliseconds();

        // handles input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            velocity += 3.125 * 19;

        // moves sprites
        bird.move(sf::Vector2f(0.f, -(velocity * dt.asSeconds())));
        pipes.move(sf::Vector2f(-200.f * dt.asSeconds(), 0.f));
        if (pipes.getPosition().x <= 178)
        {
            // -475 < y < -175
            int range = -(175) + 475 + 1;
            float num = rand() % range - 475;
            pipes.setPosition(sf::Vector2f(600.f, num));
        }

        // handles game over conditions
        if (bird.getPosition().y <= -0 || bird.getPosition().y >= 512)
            window.close();

        inTubeX = (203 >= (pipes.getPosition().x + 10)) &&\
        (203 <= (pipes.getPosition().x + 197));

        touchTube = (bird.getPosition().y <= (pipes.getPosition().y + 528))\
        || (bird.getPosition().y >= (pipes.getPosition().y + 752));

        if (inTubeX && touchTube)
            window.close();

        // drawing begins here
        window.clear();
        window.draw(background);
        window.draw(bird);
        window.draw(pipes);
        window.display();
    }

    return 0;
}