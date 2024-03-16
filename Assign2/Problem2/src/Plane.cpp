#include<iostream>
#include"Vector.h"
#include"Line.h"
#include"Plane.h"

Plane::Plane() {}

Plane::Plane(const Point& po1, const Point& po2, const Point& po3) {
	r0 = po1;
	Vector* v = new Vector;
	Point po1_2 = v->minus(po2, po1); //(po2-po1)
	Point po1_3 = v->minus(po3, po1); //(po3-po1)
	n = v->outerProduct(po1_2, po1_3);
	n = n.normalize();
	delete v;
}

Plane::~Plane(){}

Point Plane::projectTo(const Point& po) {
	Point p;
	Vector* v = new Vector;
	Vector p_r = v->minus(po, r0); //po-r0
	double p_r_n = v->innerProduct(p_r, n); //(po-r0)郴利n
	Vector p_r_n_n = v->multiply(p_r_n, n); //((po-r0)郴利n)寇利n
	p = v->minus(po, p_r_n_n); // po - ((po-r0)郴利n)寇利n
	delete v;
	return p;
}

string Plane::toString() {
	
	//"Plane: (n.x, n.y, n.z)(r - (r0.x, r0.y, r0.z))=0";

	string s1 = to_string(n.get_x());
	string s2 = to_string(n.get_y());
	string s3 = to_string(n.get_z());
	string s4 = to_string(r0.get_x());
	string s5 = to_string(r0.get_y());
	string s6 = to_string(r0.get_z());

	string s1_ = "Plane: (";
	string s2_ = ", ";
	string s3_ = ")(r - (";
	string s4_ = "))=0";

	string s = s1_ + s1 + s2_ + s2 + s2_ + s3 + s3_ + s4 + s2_ + s5 + s2_ + s6 + s4_;

	return s;

}
