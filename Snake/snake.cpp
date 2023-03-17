#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Block
{
public:
    char dir; // w,a,s,d chars for direction
    sf::RectangleShape shape;
    Block(char new_dir, int x, int y) 
    { 
        shape.setSize(sf::Vector2f(20.f, 20.f)); 
        shape.setFillColor(sf::Color::Green);
        dir = new_dir;
        shape.setPosition(x, y);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake!");
    Block start('w', 100, 100);
    vector<Block> snake;
    snake.push_back(start);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int i = 0; i < snake.size(); ++i)
        {
            window.draw(snake[i].shape);
        }

        window.display();
    }

    return 0;
}