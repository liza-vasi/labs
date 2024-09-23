#pragma once

class Fraction// ����� �����
{
public:
	Fraction();
	Fraction(int  numerator);
	Fraction(int  numerator,int  denomirator);//�����������(� �����������(?))
	int numerator()const;// const ������� �  ���, ��� ��� �� ������ ������ 
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
// ������� ����� ������������ ������, ��������� � �������� 
//Fraction a(1,4);
//Fraction *fPtr=&a; ���������� ��� ������� ����� . ��� �������� ������ ������
//Fraction &fRef=a; ������ ��� ������������� ����������� ��������� 
//Fraction b(1,3);
//fPtr=new Fraction(); ���������� � ����, �������� ����� �����, ������ ���� ��������. �������"� ������ ��������, ��� ��� ��� ��������� "
//fRef=b; ������ ������� � �. �� ���� �� ������ �������� � �� �
//*fPtr=a; ������ ��������� � ��������� ����  
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