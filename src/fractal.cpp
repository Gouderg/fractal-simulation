#include "../include/fractal.h"


Fractal::Fractal(int id, int option) {
	
	this->id = id;
	this->nbIteration = 1;
	this->option = option;

	switch(id) {
		case 1:
			// Nothing to initialize
		break;
		
		case 2:
			lines.push_back(KochLine(PVector(200,500,0), PVector(400,100,0)));
			lines.push_back(KochLine(PVector(400,100,0), PVector(600,500,0)));
			lines.push_back(KochLine(PVector(600,500,0), PVector(200,500,0)));
		break;

		case 3:
			switch(option) {
				case 1:
					XMIN = -2, XMAX = 0.5, YMIN = -1.25, YMAX = 1.25; 
				break;

				case 2:
					XMIN = -1.8, XMAX = -1.7, YMIN = -0.05, YMAX = 0.05;
				break;

				case 3:
					XMIN = -1.25, XMAX = 1.25, YMIN = -1.25, YMAX = 1.25;
				break;
			}
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
			drawCircle(WIDTH/2, HEIGHT/2, 350, window, MAX_DEPTH);
		break;
		case 2:
			for (auto elt : lines) {
				elt.display(window);
			}
		break;

		case 3:
			drawMandelBrot(window);
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

	if (radius > MIN_RADIUS) {
		drawCircle(x - radius/2, y, radius/2, window, depth - 1);
		drawCircle(x + radius/2, y, radius/2, window, depth - 1);
		drawCircle(x, y - radius/2, radius/2, window, depth - 1);
		drawCircle(x, y + radius/2, radius/2, window, depth - 1);	
	}
}

void Fractal::drawMandelBrot(sf::RenderWindow *window) {
	sf::Texture* texture = new sf::Texture();

	if (!texture->create(WIDTH, HEIGHT)) {
		cout << "Echec création de la texture" << endl;
	}

	sf::Uint8* pixels = new sf::Uint8[WIDTH * HEIGHT * 4];
	double cx, cy, xn, yn, n, tmp_x, tmp_y;

	// Création ensemble de MandelBrot
	// Equation:
	// * x0 = y0 = 0
	// * xn+1 = xn * xn - yn * yn + cx
	// * yn+1 = 2 * xn * yn + cy


	// Principe : on balaye l'écran pixel par pixel en convertissant le pixel en un point du plan de notre repère
	// Si la suire converge, le point appartient à l'ensemble de Mandelbrot et on colore le pixel en noir
	// Sinon la suite diverge, le point n'appartient pas à l'ensemble et on colore le pixel en blanc
	int i = 0;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			i = (x % WIDTH) * 4 + y * HEIGHT * 4;
			
			// Un point C du plan de coordonnées (cx;cy) dans le repère défini par XMIN:XMAX et YMIN:YMAX
			if (option != 3) {
				cx = (x * (XMAX - XMIN) / WIDTH + XMIN);
				cy = (y * (YMIN - YMAX) / HEIGHT + YMAX);
				xn = 0;
				yn = 0;
			} else {
				xn = (x * (XMAX - XMIN) / WIDTH + XMIN);
				yn = (y * (YMIN - YMAX) / HEIGHT + YMAX);
				cx = 0.285;
				cy = 0.01;
			}

			n = 0;

			// On teste le carré de la distance < 4 car racine carré couteux
			while ((xn * xn + yn * yn) < 4 && n < MAX_ITERATION) {

				// Calcul de Mn
				tmp_x = xn;
				tmp_y = yn;
				xn = tmp_x * tmp_x - tmp_y * tmp_y + cx;
				yn = 2 * tmp_x * tmp_y + cy;
				n++;
			}

			if (n == MAX_ITERATION) {
				pixels[i] = 0;
				pixels[i+1] = 0;
				pixels[i+2] = 0;
			} else {
				pixels[i] = fmod((3 * n), 256.0);
				pixels[i+1] = fmod(n,256.0);
				pixels[i+2] = fmod((10* n), 256.0);
			}
			pixels[i+3] = 255;
		}

	}
	texture->update(pixels);

	sf::Vector2f sizeRect(WIDTH, HEIGHT);
	sf::RectangleShape rect(sizeRect);
	rect.setPosition(sf::Vector2f(0.f, 0.f));
	rect.setTexture(texture);
	window->draw(rect);
}
