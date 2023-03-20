#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake!");
    window.setFramerateLimit(5);

    sf::RectangleShape snack(sf::Vector2f(10.f, 10.f));
    snack.setFillColor(sf::Color::Red);
    snack.setPosition(100, 340);

    vector<sf::RectangleShape> snake;
    snake.push_back(sf::RectangleShape(sf::Vector2f(16, 16)));
    snake[0].setPosition(100, 100);

    srand(time(0));
    char snake_dir = 0;
    int counter = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            snake_dir = 'w';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            snake_dir = 'a';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            snake_dir = 's';
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            snake_dir = 'd';

        // updates each block's dir as the one in front of it
        for (int i = snake.size() - 1; i > 0; --i)
            snake[i].setPosition(snake[i-1].getPosition());

        // moves snake based on first block dir
        switch (snake_dir)
        {
        case 'w':
            snake[0].move(0, -20);
            break;
        case 'a':
            snake[0].move(-20, 0);
            break;
        case 's':
            snake[0].move(0, 20);
            break;
        case 'd':
            snake[0].move(20, 0);
            break;
        }

        // when snake hits snack
        if (snake[0].getPosition() == snack.getPosition())
        {
            counter = 2;
            snake.push_back(sf::RectangleShape(sf::Vector2f(16, 16)));
            snake[snake.size() - 1].setPosition(snack.getPosition());
            snack.setPosition((rand() % 25) * 20, (rand() % 25) * 20);
        }

        // game over when hitting edge of screen
        int tempx = snake[0].getPosition().x;
        int tempy = snake[0].getPosition().y;
        if (tempx < 0 || tempx > 500)
            window.close();
        else if (tempy < 0 || tempy > 500)
            window.close();

        // game over when hits itself
        if (!counter)
            for (int i = 1; i < snake.size(); ++i)
                    if (snake[0].getPosition() == snake[i].getPosition())
                        window.close();
        if (counter) --counter;

        // drawing stuff
        window.clear();

        for (int i = 0; i < snake.size(); ++i)
            window.draw(snake[i]);
        window.draw(snack);
        window.display();
    }

    return 0;
}