#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../include/pvector.h"

//#include <include/fractal.h>
// Menu de choix entre les différentes étapes
// Exeécution > 20s on arrête la simulation


// Fractal:
// 		Circle fractal
//		Koch Curve
//		Trees
// 		Mandelbrot
//		Fatou
// 		Julia



int main(int argc, char const *argv[]) {
	
	PVector v(3,4,0);
	v.setMag(10);
	std::cout << v.getX() << ", " << v.getY() << ", " << v.getZ() << std::endl;
	
	return 0;
}