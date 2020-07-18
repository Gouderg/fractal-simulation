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

		void display(sf::RenderWindow *window);
		void generate();

	private:	
		int id, nbIteration = 0;

		vector<KochLine> lines;
};