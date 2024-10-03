#include "Fraction.h"
void Fraction::setNumerator(int numerator) {
	this->numerator = numerator;
}
void Fraction::setDenominator(int denominator) {
	this->denominator = denominator;
	if (denominator == 0) {
		std::cerr << "\nERROR: denominator is 0;changing to 1\n";
		denominator = 1;
	}
}

int Fraction::getNumerator() const {
	return this->numerator;
}

int Fraction::getDenominator() const {
	return this->denominator;
}
Fraction Fraction::operator+(const Fraction b) const {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.denominator + this->denominator * b.numerator);
	c.reduce();
	return c;
}
Fraction Fraction::operator-(const Fraction b) const {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.denominator - this->denominator * b.numerator);
	c.reduce();
	return c;
}
Fraction Fraction::operator*(const Fraction b) const {
	Fraction c;
	c.setDenominator(this->denominator * b.denominator);
	c.setNumerator(this->numerator * b.numerator);
	c.reduce();
	return c;
}
Fraction Fraction::operator/(const Fraction b) const {
	Fraction c;
	c.setDenominator(this->denominator * b.numerator);
	c.setNumerator(this->numerator * b.denominator);
	c.reduce();
	return c;
}
Fraction Fraction :: operator^(double pow) const {
	if (pow == 0) {
		return Fraction(1, 1);
	}

	double base = static_cast<double>(numerator) / denominator;

	if (pow < 0) {
		base = 1.0 / base; // инверсия
		pow = -pow; 
	}

	// возведеним в степень и получяем корень для дробных степеней
	double result = std::pow(base, pow);

	const int precision = 10000; // точность до десяти тысяч
	int num = static_cast<int>(result * precision);
	Fraction c = Fraction(num, precision);
	c.reduce();
	return c;
}


bool Fraction::operator<(const Fraction b) const {
	return (this->numerator * b.denominator < this->denominator * b.numerator);
}
bool Fraction::operator>(const Fraction b) const {
	return (this->numerator * b.denominator > this->denominator * b.numerator);
}
bool Fraction::operator==(const Fraction b) const {
	return (this->numerator * b.denominator == this->denominator * b.numerator);
}
bool Fraction::operator!=(const Fraction b) const {
	return (this->numerator * b.denominator != this->denominator * b.numerator);
}

void Fraction::reduce() {
	if (numerator == 0) { 
		denominator = 0;
		return;
	}
	if (denominator == 0) {
		std::cerr << "\nERROR: denominator is 0;changing to 1\n";
		denominator = 1;
	}
	Fraction c;
	int gcd = this->gcd();
	this->setDenominator(denominator / gcd);
	this->setNumerator(numerator / gcd);
	if (this->getDenominator() < 0) {
		denominator = denominator * -1;
		numerator = numerator * -1;
	}
}

void Fraction::output() const {
	std::cout << this->numerator << '/' << this->denominator << "\n";
}

void Fraction::input() {
	std::cin >> numerator;
	std::cout << "/";
	std::cout << "\n";
	std::cin >> denominator;
	while(denominator == 0) {
		std::cerr << "\nERROR: denominator is 0;changing to 1\n";
		denominator = 1;
	}
}

double Fraction::doubleFraction() const {
	return (double(this->numerator) / double(this->denominator));
}
int Fraction::gcd() {
	int result = std::min(abs(this->denominator), abs(this->numerator));
	while (result > 0) {
		if (this->numerator % result == 0 && this->denominator % result == 0) {
			break;
		}
		result--;
	}
	return result;
}
