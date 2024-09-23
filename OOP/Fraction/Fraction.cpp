#include "Fraction.h"
//#include  <cmath>

Fraction Fraction ::  operator+(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_denominator * b.m_denominator + b.m_numerator * m_denominator);
	c.SetDenomirator(m_numerator * b.m_denominator);
	return c;
}

Fraction Fraction ::  operator-(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_denominator * b.m_denominator - b.m_numerator * m_denominator);
	c.SetDenomirator(m_numerator * b.m_denominator);
	return c;
}
Fraction Fraction ::  operator*(Fraction b)
{
	Fraction c;
	c.SetNumerator(b.m_numerator * m_denominator);
	c.SetDenomirator(m_numerator * b.m_denominator);
	return c;
}
Fraction Fraction ::  operator/(Fraction b)
{
	Fraction c;
	c.SetNumerator(m_numerator* b.m_denominator);
	c.SetDenomirator(b.m_numerator * m_denominator);
	return c;
}
Fraction Fraction::operatorSokr() {
	int i;
	Fraction c;
	if (m_denominator < m_numerator) i = m_denominator;
	if (m_denominator >= m_numerator) i = m_numerator;
	for (int j = 2;j <= i;j++) {
		if (m_denominator % j && m_numerator % j) {
			m_numerator /= j;
			m_denominator /= j;
		}
	}
	c.SetNumerator(m_numerator );
	c.SetDenomirator( m_denominator);
	return c;
	/*
	if (m_denominator < 0) {
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}*/
}

Fraction Fraction::operator>(Fraction b)
{
	b.operatorSokr();
	operatorSokr();
	if (m_numerator > b.m_numerator && m_denominator > b.m_denominator) {
		return  true;
	}
	else return false;
}

Fraction Fraction::operator<(Fraction b)
{
	b.operatorSokr();
	operatorSokr();
	if (m_numerator < b.m_numerator && m_denominator < b.m_denominator) {
		return  true;
	}
	else return false;
}
Fraction Fraction::operator==(Fraction b)
{
	b.operatorSokr();
	operatorSokr();
	if (m_numerator == b.m_numerator && m_denominator == b.m_denominator) {
		return  true;
	}
	else return false;
}
Fraction Fraction::operator!=(Fraction b)
{
	b.operatorSokr();
	operatorSokr();
	if (m_numerator != b.m_numerator && m_denominator != b.m_denominator) {
		return  true;
	}
	else return false;
}
Fraction Fraction::pow(int stepen)  {
	
	for (int i = 0; i < stepen; ++i) {
		int a = m_numerator;
		int b = m_denominator;
		m_numerator *= a;
		m_denominator *= b;
	}
	/*Fraction с;
	c.SetNumerator(1);
	c.SetDenomirator(1);
	for (int i = 0; i < step; ++i) {
		c.SetNumerator(m_numerator * c.m_numerator);
		c.SetDenomirator(m_denominator * c.m_denominator);
	}
	return c;*/
}
/*
Fraction Fraction ::  operator^()//stepen(?)
{
	Fraction c;
	c.SetNumerator(pow(n,m_numerator));
	c.SetDenomirator(pow( m_denominator,n));
	return c;
}*/
//возведение в степень 
//урок 141