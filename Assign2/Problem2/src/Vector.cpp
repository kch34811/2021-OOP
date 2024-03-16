#include<iostream>
#include"Vector.h"
#include <string>

//생성자 변수 초기화
Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::~Vector() {}

double Vector::innerProduct(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector Vector::outerProduct(Vector v1, Vector v2) {
	Vector v;
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return v;
}

Vector Vector::plus(Vector v1, Vector v2) {
	Vector v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

Vector Vector::minus(Vector v1, Vector v2) {
	Vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return v;
}

Vector Vector::multiply(double s, Vector v) {
	Vector sv;
	sv.x = s * v.x;
	sv.y = s * v.y;
	sv.z = s * v.z;
	return sv;
}

double Vector::magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::normalize() {
	Vector v;
	v.x = x / this->magnitude();
	v.y = y / this->magnitude();
	v.z = z / this->magnitude();
	return v;
}

string Vector::toString() {
	//string s = "(x, y, z)";
	string s1 = to_string(x);
	string s2 = to_string(y);
	string s3 = to_string(z);
	
	string s1_ = "(";
	string s2_ = ", ";
	string s3_ = ")";

	string s = s1_ + s1 + s2_ + s2 + s2_ + s3 + s3_;

	return s;
}

double Vector::get_x() {
	return x;
}
double Vector::get_y() {
	return y;
}
double Vector::get_z() {
	return z;
}