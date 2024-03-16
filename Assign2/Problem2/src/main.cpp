#include <iostream>
#include "Vector.h"
#include "Line.h"
#include "Plane.h"

using namespace std;
int main() {
	Point p1(6, 2, 1);
	cout << p1.toString() << endl;
	Point p2(7, 3, 9);
	cout << p2.toString() << endl;
	Point p3(5, 8, 4);
	cout << p3.toString() << endl;
	Point p14(-2, 7, -9);
	Line l1(p1, p2);
	cout << l1.toString() << endl;
	Line l2(p1, p3);
	cout << l2.toString() << endl;
	Plane pl1(p1, p2, p3);
	cout << pl1.toString() << endl;
	Point p4 = pl1.projectTo(p14);
	cout << p4.toString() << endl;
	Point p5 = l1.projectTo(p14);
	cout << p5.toString() << endl;
	return 0;
}