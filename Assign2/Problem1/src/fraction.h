#pragma once

#include<iostream>

class Fraction
{
private:
	long long int numerator;
	long long int denominator;

public:
	
	Fraction();
	Fraction(long long int numer);
	Fraction(long long int numer, long long int denom);
	Fraction(const Fraction& copyFrom);
	~Fraction();
	void store(long long int numer, long long int denom);
	inline void print() const {
		std::cout << numerator << "/" << denominator << std::endl;
	}

	long long int getnum() const;
	long long int getden() const;
	void setnum(int num);
	void setden(int den);

	Fraction& operator++();

	const Fraction operator++(int);

	Fraction& operator=(const Fraction& fr);

	Fraction& operator+=(const Fraction& fr);

	Fraction operator+(const Fraction& fr);

	Fraction operator-(const Fraction& fr);

	Fraction operator*(const Fraction& fr);

	Fraction operator/(const Fraction& fr);
};