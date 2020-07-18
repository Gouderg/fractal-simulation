#include "../include/kochline.h"

KochLine::KochLine(PVector a, PVector b) {
	start = PVector(a);
	end = PVector(b);
}

void KochLine::display(sf::RenderWindow *window) {
	sf::Vertex line[] =  {
		sf::Vertex(sf::Vector2f(start.getX(), start.getY())),
		sf::Vertex(sf::Vector2f(end.getX(), end.getY())),
	};
	window->draw(line,2,sf::Lines);
}

void KochLine::generate(vector<KochLine> &lines) {
	vector<KochLine> next;

	for (auto elt : lines) {

		PVector a(elt.kochA());
		PVector b(elt.kochB());
		PVector c(elt.kochC());
		PVector d(elt.kochD());
		PVector e(elt.kochE());


		next.push_back(KochLine(a,b));
		next.push_back(KochLine(b,c));
		next.push_back(KochLine(c,d));
		next.push_back(KochLine(d,e));
	}
	lines = next;
}

PVector KochLine::kochA() {
	return PVector(start.getX(), start.getY(), start.getZ());
}

PVector KochLine::kochB() {
	PVector v = PVector::sub(end, start);
	v.div(3);
	v.add(start);
	return v;
}	

PVector KochLine::kochC() {
	PVector a(start.getX(), start.getY(), start.getZ());
	PVector v = PVector::sub(end, start);
	v.div(3);
	a.add(v);
	v.rotate2D(-60);
	a.add(v);
	return a;
}	

PVector KochLine::kochD() {
	PVector v = PVector::sub(end, start);
	v.mult(2/3.0);
	v.add(start);
	return v;
}	

PVector KochLine::kochE() {
	return PVector(end.getX(), end.getY(), end.getZ());
}	
