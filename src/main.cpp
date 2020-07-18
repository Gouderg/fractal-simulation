#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "../include/pvector.h"
#include "../include/fractal.h"
#include "../include/kochline.h"

using namespace std;

int main(int argc, char const *argv[]) {

	int id = 0;
	bool isCheck = true, isFast = true;
	do {
		cout << "----------------------------------------- \n";
		cout << "- 1. Circle Fractal                     - \n";
		cout << "- 2. Koch Curve                         - \n";
		cout << "- 3. Trees                              - \n";
		cout << "- 4. Mandelbrot                         - \n";
		cout << "- 5. Fatou                              - \n";
		cout << "- 6. Julia                              - \n";
		cout << "----------------------------------------- \n\n";

		cout << "Veuillez choisir un fractal: ";
		cin >> id;

		// Empêche le programme de planter
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (id >= 1 && id <= 6) isCheck = false;
	
	} while (isCheck);

	

	Fractal fractal(id);

	// Initialisation de l'antialiasing et de la fenêtre
	sf::ContextSettings settings;
	sf::Clock clock;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800,800), "Fractal", sf::Style::Default, settings);
	window.setFramerateLimit(1);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre
		}

		// On regarde le temps écoulé entre chaque génération
		sf::Time elapsed = clock.getElapsedTime();
		clock.restart();
		
		if ((elapsed.asSeconds() < 2) && isFast) {
			// On nettoie notre écran
			window.clear(sf::Color(25,25,100,80));

			fractal.generate();
			fractal.display(&window);

			window.display();
		} else {
			isFast = false;
		}
	}
	
	return 0;
}