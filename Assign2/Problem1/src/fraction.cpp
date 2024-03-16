#include <iostream>
#include "fraction.h"


void abbreviate(long long int* numer, long long int* denom);

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(long long int numer) {
	numerator = numer;
	denominator = 1;
}

Fraction::Fraction(long long int numer, long long int denom) {
	numerator = numer;
	denominator = denom;
	if (denominator == 0) {
		std::cout << "danominator is 0";
		return;
	}
	if (numer > 0 && denom < 0) {
		numerator = 0 -static_cast<long long>(numer);
		denominator = 0 - static_cast<long long>(denom);
	}
	abbreviate(&numerator, &denominator);
}


Fraction::Fraction(const Fraction& copyFrom) {
	numerator = copyFrom.getnum();
	denominator = copyFrom.getden();
}

Fraction::~Fraction() {}

void Fraction::store(long long int numer, long long int denom) {
	numerator = numer;
	denominator = denom;
	if (denominator == 0) {
		std::cout << "danominator is 0";
		return; 
	}
	if (numer > 0 && denom < 0) {
		numerator = 0 - static_cast<long long>(numer);
		denominator = 0 - static_cast<long long>(denom);
	}
	abbreviate(&numerator, &denominator);
}

long long int Fraction::getnum() const {
	return numerator;
}
long long int Fraction::getden() const {
	return denominator;
}
void Fraction::setnum(int num) {
	numerator = num;
}
void Fraction::setden(int den) {
	denominator = den;
	if (denominator == 0) {
		std::cout << "danominator is 0";
		return;
	}
}

Fraction& Fraction::operator++() {
	numerator += denominator;
	return *this;
}

const Fraction Fraction::operator++(int) {
	const Fraction fr(numerator, denominator);
	numerator += denominator;
	return fr;
}

Fraction& Fraction::operator=(const Fraction& fr) {
	numerator = fr.numerator;
	denominator = fr.denominator;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& fr) {
	numerator = numerator * fr.denominator + denominator * fr.numerator;
	denominator *= fr.denominator;
	abbreviate(&numerator, &denominator);
	return *this;
}


Fraction Fraction::operator+(const Fraction& fr) {
	return Fraction(numerator * fr.denominator + denominator * fr.numerator, denominator * fr.denominator);
}


Fraction Fraction::operator-(const Fraction& fr) {
	return Fraction(numerator * fr.denominator - denominator * fr.numerator, denominator * fr.denominator);
}


Fraction Fraction::operator*(const Fraction& fr) {
	return Fraction(numerator * fr.numerator, denominator * fr.denominator);
}

Fraction Fraction::operator/(const Fraction& fr) {
	return Fraction(numerator * fr.denominator, denominator * fr.numerator);
}

//약분해주는 함수
void abbreviate(long long int *num, long long int *denom) {
	long long int down = *num, up = *denom, com = 1;
	if (*num > *denom) {
		down = *denom;
		up = *num;
	}
	for (long long int i = 1; i <= down; i++) {
		if ((down % i) == 0 && (up % i) == 0)
			com = i;
	}
	*num /= com;
	*denom /= com;
}

