#include "../include/pvector.h"

PVector::PVector(const double x, const double y, const double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void PVector::set(const double x, const double y, const double z) {
	this->x = x;
	this->y = y;
	this->z = z;	
}

// Add function
void PVector::add(const PVector v1) {
	this->x += v1.x;
	this->y += v1.y; 
	this->z += v1.z; 
}

void PVector::add(const double x, const double y, const double z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

PVector PVector::add(const PVector v1, const PVector v2) {
	PVector v;
	
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;

	return v;
}

// Sub function
void PVector::sub(const PVector v1) {
	this->x -= v1.x;
	this->y -= v1.y; 
	this->z -= v1.z; 
}

void PVector::sub(const double x, const double y, const double z) {
	this->x -= x;
	this->y -= y;
	this->z -= z;
}

PVector PVector::sub(const PVector v1, const PVector v2) {
	PVector v;
	
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;

	return v;
}

// Mult function
void PVector::mult(const double n) {
	this->x *= n;
	this->y *= n;
	this->z *= n;
}

PVector PVector::mult(const PVector v1, const double n) {
	PVector v;
	v.x = v1.x * n;
	v.y = v1.y * n;
	v.z = v1.z * n;
	return v;
}

// Div function
void PVector::div(const double n) {
	this->x /= n;
	this->y /= n;
	this->z /= n;
}

PVector PVector::div(const PVector v1, const double n) {
	PVector v;
	v.x = v1.x / n;
	v.y = v1.y / n;
	v.z = v1.z / n;
	return v;
}

// Magnitude function
double PVector::mag() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

// Distance between 2 vectors
double PVector::dist(const PVector v) {
	return sqrt(pow(this->x - v.x, 2) + pow(this->y - v.y, 2) + pow(this->z - v.z, 2));
}

double PVector::dist(const PVector v1, const PVector v2) {
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

// Dot product
double PVector::dot(const PVector v) {
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

double PVector::dot(const double x, const double y, const double z) {
	return this->x * x + this->y * y + this->z * z;
}

double PVector::dot(const PVector v1, const PVector v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Cross product
PVector PVector::cross(const PVector v1) {
	PVector v;
	v.x = this->y * v1.z - this->z * v1.y;
	v.y = this->z * v1.x - this->x * v1.z;
	v.z = this->x * v1.y - this->y * v1.x;
	return v;	
}

PVector PVector::cross(const PVector v1, const PVector v2) {
	PVector v;
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return v;
}

// Normalize
void PVector::normalize() {
	double m = this->mag();
	if (m > 0) {
		this->x /= m;
		this->y /= m;
		this->z /= m;
	}
}

// Limit
void PVector::limit(const double max) {
	if (this->mag() > max) {
		this->normalize();
		this->mult(max);
	}
}

// Set Magnitude
void PVector::setMag(const double len) {
	this->normalize();
	this->mult(len);
}

// Rotate 
void PVector::rotate2D(double angle) {
	angle *= (M_PI/180);

	double tempX = this->x;
	this->setX(this->x * cos(angle) - this->y * sin(angle));
	this->setY(tempX * sin(angle) + this->y * cos(angle));
}

// Heading
double PVector::heading2D() {
	return atan(this->y/this->x);
}