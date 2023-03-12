#include <SFML/Graphics.hpp>

const float BALL_DV = 3.125 * 3.125;
const float PADDLE_DV = 1.9 * 3.125;
const int WIN_X_LEN = 800;
const int WIN_Y_LEN = 600;

void ball_reset(sf::CircleShape &ball, sf::Vector2f &ball_v) 
{
	ball.setPosition(WIN_X_LEN / 2, WIN_Y_LEN / 7);
    ball_v.x = -BALL_DV;
    ball_v.y = BALL_DV;
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WIN_X_LEN, WIN_Y_LEN), "Pong!");
    // gets rid of lag
    window.setFramerateLimit(60);

    // defining the two paddles and ball
    sf::RectangleShape l_Rect(sf::Vector2f(25.f, 100.f));
    sf::RectangleShape r_Rect(sf::Vector2f(25.f, 100.f));
    sf::CircleShape ball(7.f);
    // placing them on the board for their opening
    l_Rect.setPosition(10, WIN_Y_LEN / 2);
    r_Rect.setPosition(WIN_X_LEN - 35, WIN_Y_LEN / 2);
	// sets starting velocity for the ball
    sf::Vector2f ball_v;
    ball_reset(ball, ball_v);

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

        // moves paddles based on keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
			l_Rect.getPosition().y >= 0)
    		l_Rect.move(0, -(PADDLE_DV));

    	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
			l_Rect.getPosition().y <= WIN_Y_LEN - 100)
       		l_Rect.move(0, PADDLE_DV);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
			r_Rect.getPosition().y >= 0)
        	r_Rect.move(0, -(PADDLE_DV));

   		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
			r_Rect.getPosition().y <= WIN_Y_LEN - 100)
        	r_Rect.move(0, PADDLE_DV);

        // ball-paddle logic
        // left paddle vvv
        if (ball.getPosition().x <= 10)
        {
           if (ball.getPosition().y >= l_Rect.getPosition().y &&
            ball.getPosition().y <= (l_Rect.getPosition().y +
                l_Rect.getSize().y))
            ball_v.x = -(ball_v.x);
        }
        // right paddle vvv
        if (ball.getPosition().x >= WIN_X_LEN - 35)
        {
            if (ball.getPosition().y >= r_Rect.getPosition().y &&
            ball.getPosition().y <= (r_Rect.getPosition().y +
                r_Rect.getSize().y))
            ball_v.x = -(ball_v.x);
        }

    	// ball-wall logic
        if (ball.getPosition().y >= WIN_Y_LEN)
        	ball_v.y = -(ball_v.y);
        else if (ball.getPosition().y <= 0)
        	ball_v.y = -(ball_v.y);
        else if (ball.getPosition().x >= WIN_X_LEN)
        	ball_reset(ball, ball_v);
        else if (ball.getPosition().x <= 0)
        	ball_reset(ball, ball_v);

        // moves the ball with the updated velocity
    	ball.move(ball_v.x, ball_v.y);

        // closes window when Esc is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        	window.close();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draws the shapes
        window.draw(l_Rect);
        window.draw(r_Rect);
        window.draw(ball);

        // end the current frame
        window.display();
    }

    return 0;
}