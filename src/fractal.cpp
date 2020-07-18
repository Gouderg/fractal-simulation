#include "../include/fractal.h"


Fractal::Fractal(int id) {
	
	this->id = id;
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
		case 2:
			for (auto elt : lines) {
				elt.display(window);
			}
		break;
	}
}