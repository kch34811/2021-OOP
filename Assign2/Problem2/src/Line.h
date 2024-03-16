#pragma once


class Line 
{
private:
	Vector l, l0;

public:
	Line();
	Line(const Point& po1, const Point& po2);
	~Line();
	Point projectTo(const Point& po);
	string toString();
};
