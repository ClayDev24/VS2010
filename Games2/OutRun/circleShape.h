#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void _circleShape() {
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

	sf::Event event;

	sf::CircleShape circle;
	circle.setRadius(150);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);
	circle.setPosition(10, 20);

	//sf::CircleShape circleShape(200);
	//circleShape.setFillColor(sf::Color::Blue);

	while (renderWindow.isOpen()){
		while (renderWindow.pollEvent(event)){
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}
		
		renderWindow.clear();
		renderWindow.draw(circle);
		renderWindow.display();
	}

}