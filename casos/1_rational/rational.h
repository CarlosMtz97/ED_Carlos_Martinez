 /*
 * rational.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>

class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	Rational& operator=   (const Rational&);
	void operator+=  (const Rational&);

	operator double () const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

Rational::Rational(int num, int dem){  
  numerator = num;
  denominator = dem;
  normalize();    
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

std::string Rational::toString() const {
	std::stringstream aux;
	aux << numerator << "/" << denominator;
	return aux.str();
}

Rational::operator double () const {
	return 0.0;
}

//Greatest common divisor
int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

void Rational::normalize() {
  int aux = 0;
  int aux_sign = 1;
  if (denominator == 0) {
		throw RangeError();
	}
  if (numerator < 0 || denominator < 0)
    aux_sign = -1;
  if (numerator < 0 && denominator < 0)
    aux_sign = 1;
  
  aux = gcd(numerator,denominator);
  
  numerator = abs(numerator / aux) * aux_sign;
  denominator = abs(denominator / aux);
  
}

Rational& Rational::operator= (const Rational &right) {
  numerator = right.numerator;
  denominator = right.denominator;
  return *this; 
}

void Rational::operator+= (const Rational &right) {
}

Rational operator+ (const Rational &left, const Rational &right) {
	return Rational();
}

Rational operator- (const Rational &left, const Rational &right) {
	return Rational();
}

Rational operator- (const Rational &right) {
	return Rational();
}

bool operator== (const Rational &left, const Rational &right) {
	return false;
}

bool operator<  (const Rational &left, const Rational &right) {
	return false;
}

#endif /* RATIONAL_H_ */
