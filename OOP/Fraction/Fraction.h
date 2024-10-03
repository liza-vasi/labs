#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath> 
class Fraction
{

public:
	Fraction(int numerator = 1, int denominator = 2) {
		setNumerator(numerator);//установление
		setDenominator(denominator);//услановление
	}
	void setNumerator(int numerator);
	void setDenominator(int denominator);
	int getNumerator() const;
	int getDenominator() const;

	Fraction operator+(const Fraction b) const;
	Fraction operator-(const Fraction b) const;
	Fraction operator*(const Fraction b) const;
	Fraction operator/(const Fraction b) const;

	Fraction operator^(double pow) const;// возведение в степень

	bool operator<(const Fraction b) const;
	bool operator>(const Fraction b) const;
	bool operator==(const Fraction b) const;
	bool operator!=(const Fraction b) const;

	void reduce();//сокращение

	void output() const;//вывод
	void input();//ввод
	double doubleFraction() const;
private:
	int numerator;
	int denominator;
	int gcd();//нахождение нод

};

/**/