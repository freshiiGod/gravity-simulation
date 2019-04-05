#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity", sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
				break;
			}
		}
		//clear window with black color
		window.clear(sf::Color::Black);

		//select what to draw: window.draw(...)


		//actually draw objects
		window.display();
	}

	return 0;
}