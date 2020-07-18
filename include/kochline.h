#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../include/pvector.h"

using namespace std;

class KochLine {
	public:
		KochLine(PVector a, PVector b);
		~KochLine(){};

		void display(sf::RenderWindow *window);
		static void generate(vector<KochLine> &lines);

		PVector kochA();
		PVector kochB();
		PVector kochC();
		PVector kochD();
		PVector kochE();


	private:
		PVector start;
		PVector end;
};