#pragma once

#include <iostream>
#include <vector>
#include "../include/kochline.h"
#include "../include/pvector.h"


using namespace std;

class Fractal {
	
	public:
		// Dimension de la fenêtre
		const int WIDTH = 700;
		const int HEIGHT = 700;

		// Constante Circle
		const int MIN_RADIUS = 8;
		const int MAX_DEPTH = 9;

		// Constantes MandelBrot
		const int MAX_ITERATION = 2000;
		

		Fractal(int id, int option);
		~Fractal(){};

		// Setter
		void setIteration(int const incr) {this->nbIteration = incr;}

		// Getter
		int getIteration() const {return this->nbIteration;}
		int getId() const {return this->id;}
		int getOption() const {return this->option;}

		void display(sf::RenderWindow *window);
		void generate();
		void drawCircle(double x, double y, double radius, sf::RenderWindow *window, int depth);
		void drawMandelBrot(sf::RenderWindow *window);


	private:	
		int id, option, nbIteration;
		double XMIN, XMAX, YMIN, YMAX; 

		vector<KochLine> lines;
};