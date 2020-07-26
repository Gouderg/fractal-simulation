#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "../include/pvector.h"
#include "../include/fractal.h"
#include "../include/kochline.h"

using namespace std;

void initChoice(int &id, int &option);

int main(int argc, char const *argv[]) {

	int id = 0, option = 0;
	initChoice(id, option);

	Fractal fractal(id, option);
	int zoom = 100;
	// Initialisation de l'antialiasing et de la fenêtre
	sf::ContextSettings settings;
	sf::View view;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(fractal.WIDTH, fractal.HEIGHT), "Fractal", sf::Style::Default, settings);
	window.setFramerateLimit(2);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre

			if (event.type == sf::Event::MouseButtonPressed) {
				window.clear(sf::Color(25,25,100,80));
				view = window.getDefaultView();
				view.setCenter(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				if (event.mouseButton.button == sf::Mouse::Left) view.setSize(sf::Vector2f(zoom, zoom));
				window.setView(view);
				fractal.display(&window);
			}

		}
		
		// Empêche la récursion d'aller trop loin
		if (fractal.getIteration() < 10 && fractal.getId() == 2) {
			window.clear(sf::Color(25,25,100,80));
			fractal.generate();
			fractal.display(&window);

		} else if (fractal.getIteration() < 2) {
			window.clear(sf::Color(25,25,100,80));
			fractal.generate();
			fractal.display(&window);
		}
		window.display();
		fractal.setIteration(fractal.getIteration() + 1);

	}

	return 0;
}


void initChoice(int &id, int &option) {

	bool isCheck = true;
	do {
		cout << "----------------------------------------- \n";
		cout << "- 1. Circle Fractal                     - \n";
		cout << "- 2. Koch Curve                         - \n";
		cout << "- 3. Mandelbrot                         - \n";
		cout << "----------------------------------------- \n\n";

		cout << "Veuillez choisir un fractal: ";
		cin >> id;

		// Empêche le programme de planter
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (id >= 1 && id <= 3) isCheck = false;
	
	} while (isCheck);	
	
	if (id == 3) {
		isCheck = true;
		do {
			cout << "----------------------------------------- \n";
			cout << "- 1. Normal                             - \n";
			cout << "- 2. Zoom                               - \n";
			cout << "- 3. Julia pour un paramère fixé        - \n";
			cout << "----------------------------------------- \n\n";

			cout << "Veuillez un des modèles de MandelBrot: ";
			cin >> option;

			// Empêche le programme de planter
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (option >= 1 && option <= 3) isCheck = false;
		
		} while (isCheck);
	}
}