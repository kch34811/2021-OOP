#pragma once


class Plane 
{
private:
	Vector n, r0;
public:
	Plane();
	Plane(const Point& po1, const Point& po2, const Point& po3);
	~Plane();
	Point projectTo(const Point& po);
	string toString();
};
