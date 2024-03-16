#pragma once

#include <string>

using namespace std;

class Vector 
{
private:
	double x, y, z;

public:
	Vector();
	Vector(double x, double y, double z);
	~Vector();
	double innerProduct(Vector v1, Vector v2);
	Vector outerProduct(Vector v1, Vector v2);
	Vector plus(Vector v1, Vector v2);
	Vector minus(Vector v1, Vector v2);
	Vector multiply(double s, Vector v);
	double magnitude();
	Vector normalize();
	string toString();

	//추가적으로 구현한 getter
	double get_x();
	double get_y();
	double get_z();
	
};

typedef Vector Point;
