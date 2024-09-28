#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath> 
class Fraction
{

public:
	Fraction(int numerator=1 , int denominator=2 ) {
		setNumerator(numerator);//установление
		setDenominator(denominator);//услановление
	}
	
	void setNumerator(int numerator) {
		this->numerator = numerator;
	}
	void setDenominator(int denominator) {
		this->denominator = denominator;
	}
	int getNumerator() {
		return this->numerator;//получение
	}
	int getDenominator() {
		return this->denominator;//получение
	}

	Fraction operator+(const Fraction b);
	Fraction operator-(const Fraction b);
	Fraction operator*(const Fraction b);
	Fraction operator/(const Fraction b);

	Fraction operator^(int pow);// возведение в степень

	bool operator<(const Fraction b);
	bool operator>(const Fraction b);
	bool operator==(const Fraction b);
	bool operator!=(const Fraction b);

	void reduce();//сокращение

	void outputFraction() const;//вывод
	Fraction inputFraction() const;//ввод

	

	double doubleFraction() const;
private:
	int numerator;
	int denominator;
	int gcd();//нахождение нод

};

/**/