#include<iostream>
#include <cmath>
#include"Vector.h"
#include"Line.h"

Line::Line() {}

Line::Line(const Point& po1, const Point& po2) {
	l0 = po1;
	Vector* v = new Vector;
	l = v->minus(po2, po1);
	delete v; 
}

Line::~Line() {}

Point Line::projectTo(const Point& po) {
	
	Point p;
	Vector* v = new Vector;
	
	//p = l0 + (((po-l0)•l)/(l•l)) l
	
	Vector P_Lorg = v->minus(po, l0); //po-l0
	double P_Lorg_Ldir = v->innerProduct(P_Lorg, l); //(po-l0)•l
	double Ldir_2 = v->innerProduct(l, l); //l•l
	double pjr = P_Lorg_Ldir / Ldir_2; //(po-l0)•l/(l•l)

	Point Pprj = v->multiply(pjr, l); //(((po-l0)•l)/(l•l)) l
	p = v->plus(l0, Pprj); //l0 + (((po-l0)•l)/(l•l)) l

	delete v;

	return p;
}

string Line::toString() {
	

	string s1 = to_string(l.get_x());
	string s2 = to_string(l.get_y());
	string s3 = to_string(l.get_z());
	string s4 = to_string(l0.get_x());
	string s5 = to_string(l0.get_y());
	string s6 = to_string(l0.get_z());
	
	string s1_ = "Line: (";
	string s2_ = ", ";
	string s3_ = ")t + (";
	string s4_ = ")";

	string s = s1_ + s1 + s2_ + s2 + s2_ + s3 + s3_ + s4 + s2_ + s5 + s2_ + s6 + s4_;

	return s;
}