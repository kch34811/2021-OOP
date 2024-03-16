#include <iostream>
#include "Fraction.h"

int main() {
	Fraction fr1;
	fr1.store(1234, 5678);
	Fraction fr2(97637, -789);
	Fraction fr3;

	fr3 = fr1 + fr2;
	std::cout << "value of fr3 after fr3 = fr1 + fr2 operation : ";
	fr3.print();

	fr3 = fr1 - fr2;
	std::cout << "value of fr3 after fr3 = fr1 - fr2 operation : ";
	fr3.print();

	fr3 = fr1 * fr2;
	std::cout << "value of fr3 after fr3 = fr1 * fr2 operation : ";
	fr3.print();

	fr3 = fr1 / fr2;
	std::cout << "value of fr3 after fr3 = fr1 / fr2 operation : ";
	fr3.print();

	fr2 = fr1;
	std::cout << "value of fr2 after fr2 = fr1 operation : ";
	fr2.print();

	fr2 += fr1;
	std::cout << "value of fr2 after fr2 += fr1 operation : ";
	fr2.print();

	fr2++;
	std::cout << "value of fr2 after fr2++ operation : ";
	fr2.print();

	++fr2;
	std::cout << "value of fr2 after ++fr2 operation : ";
	fr2.print();

	return 0;
}