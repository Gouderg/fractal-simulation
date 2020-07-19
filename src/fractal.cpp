#include "../include/fractal.h"


Fractal::Fractal(int id) {
	
	this->id = id;
	this->nbIteration = 1;

	switch(id) {
		case 1:

		break;
		case 2:
			lines.push_back(KochLine(PVector(200,500,0), PVector(400,100,0)));
			lines.push_back(KochLine(PVector(400,100,0), PVector(600,500,0)));
			lines.push_back(KochLine(PVector(600,500,0), PVector(200,500,0)));
		break;
	}
}

void Fractal::generate() {

	switch(id) {
		case 2:
			KochLine::generate(lines);
		break;
	}
}

void Fractal::display(sf::RenderWindow *window) {
	
	switch(id) {
		case 1:
			drawCircle(700/2, 700/2, 350, window, 9);
		break;
		case 2:
			for (auto elt : lines) {
				elt.display(window);
			}
		break;
	}
}

void Fractal::drawCircle(double x, double y, double radius, sf::RenderWindow *window, int depth) {

	if (!depth) return;

	sf::CircleShape shape(radius);
	shape.setPosition(x - radius, y - radius);
	shape.setFillColor(sf::Color(25, 25, 100, 0));
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(sf::Color(237, 2, 245));
	window->draw(shape);

	if (radius > 8) {
		drawCircle(x - radius/2, y, radius/2, window, depth - 1);
		drawCircle(x + radius/2, y, radius/2, window, depth - 1);
		drawCircle(x, y - radius/2, radius/2, window, depth - 1);
		drawCircle(x, y + radius/2, radius/2, window, depth - 1);	
	}
}