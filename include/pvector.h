#pragma once

#include <cmath>

class PVector {

	public:
		PVector(){};
		PVector(const double x, const double y, const double z);
		~PVector(){};

		// Add
		void add(const PVector v1);
		void add(const double x, const double y, const double z);
		static PVector add(const PVector v1, const PVector v2);

		// Sub
		void sub(const PVector v1);
		void sub(const double x, const double y, const double z);
		static PVector sub(const PVector v1, const PVector v2);	

		// Mult
		void mult(const double n);
		static PVector mult(const PVector v1, const double n);

		// Div
		void div(const double n);
		static PVector div(const PVector v1, const double n);

		// Magnitude
		double mag();

		// Distance between 2 vectors
		double dist(const PVector v);
		static double dist(const PVector v1, const PVector v2);

		// Dot product
		double dot(const PVector v);
		double dot(const double x, const double y, const double z);
		static double dot(const PVector v1, const PVector v2);

		// Cross product
		PVector cross(const PVector v1);
		static PVector cross(const PVector v1, const PVector v2);

		// Normalize
		void normalize();

		// Limit vector
		void limit(const double max);

		// Set Magnitude
		void setMag(const double len);

		// Setter
		void set(const double x, const double y, const double z);
		void setX(const double x) {this->x = x;}
		void setY(const double y) {this->y = y;}
		void setZ(const double z) {this->z = z;}

		// Getter
		double getX() const {return this->x;}
		double getY() const {return this->y;}
		double getZ() const {return this->z;}


	private:
		double x, y, z;
};