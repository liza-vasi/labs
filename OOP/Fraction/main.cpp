#include "Fraction.h"
#include <iostream>
#include <conio.h>
int main()
{
	std::cout << "Fraction f1:" << "\n";
	Fraction f1;
	f1.input();
	
	std::cout << "Fraction f2:" << "\n";
	Fraction f2;
	f2.input();
	
	std::cout << "f1+f2=";
	(f1 + f2).output();
	std::cout << "f1 - f2=";
	(f1 - f2).output();
	std::cout << "f1 * f2=";
	(f1 * f2).output();
	std::cout << "f1 / f2=";
	(f1 / f2).output();
	std::cout << "f1 > f2 " << ((f1 > f2) ? "True" : "False") << "\n";
	std::cout << "f1 < f2 " << ((f1 < f2) ? "True" : "False") << "\n";
	std::cout << "f1 == f2 " << ((f1 == f2) ? "True" : "False") << "\n";
	std::cout << "f1 != f2 " << ((f1 != f2) ? "True" : "False") << "\n";

	double pow1;
	std::cout << "pow  f1: ";
	std::cin >> pow1;
	(f1 ^ pow1).output();
	double pow2;
	std::cout << "pow  f2: ";
	std::cin >> pow2;
	(f2 ^ pow2).output();

	std::cout << "f1 double "<<f1.doubleFraction()<<"\n";
	std::cout << "f2 double " << f2.doubleFraction() << "\n";

	_getch();
	return 0;
}