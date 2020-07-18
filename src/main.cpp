#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "../include/pvector.h"
#include "../include/fractal.h"
#include "../include/kochline.h"

#define WIDTH 800
#define HEIGHT 700

using namespace std;

int main(int argc, char const *argv[]) {

	int id = 0;
	bool isCheck = true;
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
	double zoom = 1;
	// Initialisation de l'antialiasing et de la fenêtre
	sf::ContextSettings settings;
	sf::View view;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Fractal", sf::Style::Default, settings);
	window.setFramerateLimit(2);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre
		}
		
		if (fractal.getIteration() < 10) {
			// On nettoie notre écran
			window.clear(sf::Color(25,25,100,80));
			fractal.generate();
			fractal.display(&window);			
		}

		if (fractal.getIteration() >= 11) {
			window.setFramerateLimit(60);
			window.clear(sf::Color(25,25,100,80));
			view = window.getDefaultView();
			view.setCenter(sf::Vector2f(400.f, 100.f));
			view.setSize(sf::Vector2f(zoom, zoom));
			window.setView(view);
			fractal.display(&window);
			zoom += 0.1;
		}



		window.display();
		fractal.setIteration(fractal.getIteration() + 1);
	}
	
	return 0;
}