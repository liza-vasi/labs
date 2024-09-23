#pragma once

class Fraction// класс дроби
{
public:
	Fraction();
	Fraction(int  numerator);
	Fraction(int  numerator,int  denomirator);//конструктор(с параметрами(?))
	int numerator()const;// const говорит о  том, что это не меняет объект 
	int denomirator()const;
	int n() const;
	void SetNumerator(int numerator);
	void SetDenomirator(int denomirator);
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);

	//Fraction operatorSokr(Fraction);
	
	Fraction operator>(Fraction);
	Fraction operator<(Fraction);
	Fraction operator==(Fraction);
	Fraction operator!=(Fraction);

    Fraction pow(int stepen);
    Fraction Double(double drob, int zapatue);
    void coutt() {
        cout << "\t" << numerator;
        cout << "/" << denomirator;
    }
	//Fraction operator^(int n);
private:
	int m_numerator;
	int m_denominator;
	Fraction operatorSokr();

};
/*
Fracton pow(int n) {
	if (n < 0) {
		invert();
		n=-n
	}
}
// разница между копированием ссылки, указателя и значения 
//Fraction a(1,4);
//Fraction *fPtr=&a; переменная тип которой адрес . это операция взятия адреса
//Fraction &fRef=a; ссылка это разименованый константный указатель 
//Fraction b(1,3);
//fPtr=new Fraction(); обращается к куче, выделает кусок помяи, кладет туда значение. Говорит"Я помять выделила, она вон там находится "
//fRef=b; ссылка связана с а. то есть мы меняем значение а на б
//*fPtr=a; прямое обращение к непонятно чему  
// delete fPtr;*/
/*
#include <iostream>
#include <sstream>
using namespace std;

class Fraction {
public:
    Fraction() {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den) {}

    friend ostream& operator<<(ostream& os, const Fraction& frac);
    friend istream& operator>>(istream& is, Fraction& frac);

    Fraction pow(int exp) const;
    static Fraction fromDouble(double d, int precision);

private:
    int m_numerator;
    int m_denominator;
};

ostream& operator<<(ostream& os, const Fraction& frac) {
    return os << frac.m_numerator << "/" << frac.m_denominator;
}

istream& operator>>(istream& is, Fraction& frac) {
    string numStr, denStr;
    getline(is, numStr, '/');
    getline(is, denStr);

    istringstream issNum(numStr);
    istringstream issDen(denStr);

    int num, den;
    issNum >> num;
    issDen >> den;

    frac = Fraction(num, den);
    return is;
}

Fraction Fraction::pow(int exp) const {
    Fraction result(1, 1);
    for (int i = 0; i < exp; ++i) {
        result *= *this;
    }
    return result;
}

Fraction Fraction::fromDouble(double d, int precision) {
    double scaled = d * pow(10, precision);
    int wholePart = static_cast<int>(scaled);
    double fractionalPart = scaled - wholePart;

    int denominator = pow(10, precision);
    int nominator = static_cast<int>(fractionalPart * denominator);

    return Fraction(wholePart, denominator) + Fraction(nominator, denominator);
}

int main() {
    Fraction frac(1, 2);
    cout << frac << endl;

    Fraction convertedFrac = Fraction::fromDouble(0.75, 2);
    cout << convertedFrac << endl;

    Fraction raisedFrac = frac.pow(2);
    cout << raisedFrac << endl;

    cin >> frac;
    cout << frac << endl;

    return 0;
}
*/