#pragma once

#include <iostream>
#include <vector>
#include "../include/kochline.h"
#include "../include/pvector.h"


using namespace std;

class Fractal {
	
	public:
		Fractal(int id);
		~Fractal(){};

		// Setter
		void setIteration(int const incr) {this->nbIteration = incr;}

		// Getter
		int getIteration() const {return this->nbIteration;}

		void display(sf::RenderWindow *window);
		void generate();

	private:	
		int id, nbIteration;

		vector<KochLine> lines;
};