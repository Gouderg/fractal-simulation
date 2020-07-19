#pragma once

#include <iostream>
#include <vector>
#include "../include/kochline.h"
#include "../include/pvector.h"


using namespace std;

class Fractal {
	
	public:
		const int WIDTH = 700;
		const int HEIGHT = 700;

		Fractal(int id);
		~Fractal(){};

		// Setter
		void setIteration(int const incr) {this->nbIteration = incr;}

		// Getter
		int getIteration() const {return this->nbIteration;}

		void display(sf::RenderWindow *window);
		void generate();
		void drawCircle(double x, double y, double radius, sf::RenderWindow *window, int depth);

	private:	
		int id, nbIteration;


		vector<KochLine> lines;
};