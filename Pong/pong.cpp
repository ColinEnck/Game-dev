#include <SFML/Graphics.hpp>

const int WIN_X_LEN = 800;
const int WIN_Y_LEN = 600;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WIN_X_LEN, WIN_Y_LEN), "Pong!");

    // defining the two paddles and ball
    sf::RectangleShape l_Rect(sf::Vector2f(25.f, 100.f));
    sf::RectangleShape r_Rect(sf::Vector2f(25.f, 100.f));
    sf::CircleShape ball(7.f);
    // placing them on the board for their opening
    l_Rect.setPosition(10, WIN_Y_LEN / 2);
    r_Rect.setPosition(WIN_X_LEN - 35, WIN_Y_LEN / 2);
    ball.setPosition(WIN_X_LEN / 2, WIN_Y_LEN / 2);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
        		l_Rect.getPosition().y >= 0)
        	l_Rect.move(0, -0.1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        		l_Rect.getPosition().y <= WIN_Y_LEN - 100)
        	l_Rect.move(0, 0.1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
				r_Rect.getPosition().y >= 0)
        	r_Rect.move(0, -0.1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
        		r_Rect.getPosition().y <= WIN_Y_LEN - 100)
        	r_Rect.move(0, 0.1);

        // closes window when Esc is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        	window.close();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(l_Rect);
        window.draw(r_Rect);
        window.draw(ball);


        // end the current frame
        window.display();
    }

    return 0;
}
