#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class ComplexNumber
{
private:
	double real;
	double imaginary;
	friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& C);
	friend std::istream& operator>>(std::istream& in, ComplexNumber& C);

public:
	ComplexNumber(double _real = 0.0, double _imaginary = 0.0);
	ComplexNumber(const ComplexNumber& C);
	~ComplexNumber();
	
	double getReal() const;
	double getImaginary() const;
	double modulus() const;

	ComplexNumber getConjugate() const;
	ComplexNumber& setReal(const double& _real);
	ComplexNumber& setImaginary(const double& _imaginary);

	ComplexNumber operator+(const ComplexNumber& C) const;
	ComplexNumber operator-(const ComplexNumber& C) const;
	ComplexNumber operator*(const ComplexNumber& C) const;
	ComplexNumber operator/(const ComplexNumber& C) const;
	
	ComplexNumber& operator=(const ComplexNumber& C);
	ComplexNumber& operator+=(const ComplexNumber& C);
	ComplexNumber& operator-=(const ComplexNumber& C);
	ComplexNumber& operator*=(const ComplexNumber& C);
	ComplexNumber& operator/=(const ComplexNumber& C);
	
	ComplexNumber& operator++();
	ComplexNumber& operator--();
	ComplexNumber operator++(int);
	ComplexNumber operator--(int);

	bool operator==(const ComplexNumber& C) const;
	bool operator!=(const ComplexNumber& C) const;
	bool operator>(const ComplexNumber& C) const;
	bool operator>=(const ComplexNumber& C) const;
	bool operator<(const ComplexNumber& C) const;
	bool operator<=(const ComplexNumber& C) const;
	bool isZero() const;

	void printComplexNumber() const;
	std::size_t size() const;
};
#endif