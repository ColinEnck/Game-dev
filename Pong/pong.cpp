#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong!");

    // defining the two paddles and ball
    sf::RectangleShape lRect(sf::Vector2f(25.f, 100.f));
    sf::RectangleShape rRect(sf::Vector2f(25.f, 100.f));
    sf::CircleShape ball(7.f);
    // placing them on the board for their opening
    lRect.setPosition(10, 300);
    rRect.setPosition(750, 300);
    ball.setPosition(400, 300);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // moves the paddles based on keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        	lRect.move(0, -0.1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        	lRect.move(0, 0.1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        	rRect.move(0, -0.1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        	rRect.move(0, 0.1);

        // closes window when Esc is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        	window.close();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(lRect);
        window.draw(rRect);
        window.draw(ball);


        // end the current frame
        window.display();
    }

    return 0;
}
