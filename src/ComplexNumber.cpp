#include "../include/ComplexNumber.h"

// Constructor
ComplexNumber::ComplexNumber(double _real, double _imaginary) : real(_real), imaginary(_imaginary) {}

// Copy Constructor
ComplexNumber::ComplexNumber(const ComplexNumber& C)
{
	real = C.real;
	imaginary = C.imaginary;
}

// Destructor
ComplexNumber::~ComplexNumber() {}

// Returns the real part of the complex number
double ComplexNumber::getReal() const {
	return real;
}

// Returns the imaginary part of the complex number
double ComplexNumber::getImaginary() const {
		return imaginary;
}

// Returns the magninute (modulus) of the complex number
double ComplexNumber::modulus() const
{
	return (abs(sqrt(((real * real)+(imaginary * imaginary)))));
}

// Returns the conjugate of the complex number
ComplexNumber ComplexNumber::getConjugate() const
{
	return ComplexNumber(real, imaginary * -1);
}

// Sets the given double as the complex number's real part
ComplexNumber& ComplexNumber::setReal(const double &_real) {

	real = _real;
	return *(this);
}

// Sets the given double as the complex number's imaginary part
ComplexNumber& ComplexNumber::setImaginary(const double &_imaginary) {

	imaginary = _imaginary;
	return *(this);
}

// This function actually is not necessary anymore as "<<" operator has been defined.
// Prints the complex number.
void ComplexNumber::printComplexNumber() const
{
	std::cout << *(this);
}

// Overloaded + operator
// Returns the sum as a new complex number object
ComplexNumber ComplexNumber::operator+ (const ComplexNumber &C) const
{
	double r = real + C.real;
	double i = imaginary + C.imaginary;
	return ComplexNumber(r, i);
}

// Overloaded - operator
// Returns the difference as a new complex number object
ComplexNumber ComplexNumber::operator-(const ComplexNumber& C) const
{
	double r = real - C.real;
	double i = imaginary - C.imaginary;
	return ComplexNumber(r, i);
}

// Overloaded * opearator
// Returns the product as a new complex number object
ComplexNumber ComplexNumber::operator*(const ComplexNumber& C) const
{
	double a, b, c, d;
	a = real;
	b = imaginary;
	c = C.real;
	d = C.imaginary;

	double r = ((a*c) - (b*d));
	double i = ((b*c) + (a*d));
	return ComplexNumber(r, i);
}

// Overloaded / operator
// Returns the division as a new complex number object
// Returns 0 in case of division by zero
ComplexNumber ComplexNumber::operator/(const ComplexNumber& C) const
{
	if(!C.isZero()){
		double a, b, c, d;
		a = real;
		b = imaginary;
		c = C.real;
		d = C.imaginary;

		double r = ((a * c) + (b * d)) / ((c * c) + (d * d));
		double i = ((b * c) - (a * d)) / ((c * c) + (d * d));
		return ComplexNumber(r, i);
	}
	else {
		std::cout << "Error: Division by ";
		return C;
	}
}

// Overloaded = operator
// Sets the complex number's real and imaginary parts equal to the given complex number's real and imaginary parts
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& C)
{
	setReal(C.real);
	setImaginary(C.imaginary);
	return *(this);
}

// Overloaded += operator
// Modifies the left-hand-side complex number as the result of the sum, and returns the complex number
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& C)
{
	real += C.real;
	imaginary += C.imaginary;
	return *(this);
}

// Overloaded -= operator
// Modifies the left-hand-side complex number as the result of the subtraction, and returns the complex number
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& C)
{
	real -= C.real;
	imaginary -= C.imaginary;
	return *(this);
}

// Overloaded *= operator
// Modifies the left-hand-side complex number as the result of the product, and returns the complex number
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& C)
{
	real *= C.real;
	imaginary *= C.imaginary;
	return *(this);
}

// Overloaded /= operator
// Modifies the left-hand-side complex number as the result of the division, and returns the complex number
ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& C)
{
	if(!C.isZero()){
		real /= C.real;
		imaginary /= C.imaginary;
		return *(this);
	}
	else {
		std::cerr << "Error: Division by ";
		setReal(0); setImaginary(0); // This sets the sent Complex Number to 0!
		return *(this);
	}
}

// Increase real part by 1, imaginary part stays the same
// If imaginary part should change as well, uncomment the code
ComplexNumber& ComplexNumber::operator++()
{
	real += 1;
	//imaginary += 1;
	return *(this);
}

// Increase real part by 1, imaginary part stays the same.
// If imaginary part should change as well, uncomment the code
ComplexNumber ComplexNumber::operator++(int)
{
	ComplexNumber temp = *this;
	real += 1;
	//imaginary += 1;
	return temp;
}

// Decrease real part by 1, imaginary part stays the same.
// If imaginary part should change as well, uncomment the code
ComplexNumber& ComplexNumber::operator--()
{
	real-= 1;
	//imaginary -= 1;
	return *(this);
}

// Decrease real part by 1, imaginary part stays the same.
// If imaginary part should change as well, uncomment the code
ComplexNumber ComplexNumber::operator--(int)
{
	ComplexNumber temp = *this;
	real -= 1;
	//imaginary -= 1;
	return temp;
}

// Overloaded == operator
// Returns true if both imaginary and real parts of the complex number are equal to the given complex number's corresponding parts
bool ComplexNumber::operator==(const ComplexNumber& C) const
{
	return (real == C.real) && (imaginary == C.imaginary);
}

// Overloaded != operator
// Returns true if any of the imaginary or real parts of the complex number is not equal to the given complex number's corresponding parts
bool ComplexNumber::operator!=(const ComplexNumber& C) const
{
	return (real != C.real) || (imaginary != C.imaginary);

}

// Overloaded > operator
// Returns true if magnitude of the complex number is bigger than the given complex number's magnitude
bool ComplexNumber::operator>(const ComplexNumber& C) const
{
	return (modulus() > C.modulus());
}

// Overloaded >= operator
// Returns true if magnitude of the complex number is bigger than or equal to the given complex number's magnitude
bool ComplexNumber::operator>=(const ComplexNumber& C) const
{
	return (modulus() >= C.modulus());
}

// Overloaded < operator
// Returns true if magnitude of the complex number is smallar than the given complex number's magnitude
bool ComplexNumber::operator<(const ComplexNumber& C) const
{
	return (modulus() < C.modulus());
}

// Overloaded <= operator
// Returns true if magnitude of the complex number is smaller than or equal to the given complex number's magnitude
bool ComplexNumber::operator<=(const ComplexNumber& C) const
{
	return (modulus() <= C.modulus());
}

// Returns true if the complex number's real and imaginary parts are both zero.
bool ComplexNumber::isZero() const
{
	return (real == 0 && imaginary == 0);
}

// Returns the size of Complex Number in Bytes!
std::size_t ComplexNumber::size() const
{
	return sizeof(*this); 
}

// Overloaded << operator
// Makes it possible to use "cout << ComplexNumberObject"
std::ostream& operator<<(std::ostream& out, const ComplexNumber& C)
{
	// Add + sign if imaginary part is positive
	if (C.imaginary > 0 && C.real != 0) {
		out << C.real << " + " << C.imaginary << "i";
	}
	// Don't print imaginary part if it is zero
	else if (C.imaginary == 0 && C.real != 0) {
		out << C.real;
	}
	// Don't print real part if it is zero
	else if (C.real == 0 && C.imaginary != 0) {
		out << C.imaginary;
	}
	// Print zero if both parts are zero
	else if (C.real == 0 && C.imaginary == 0) {
		out << 0;
	}
	// Add spacing to the minus sign for better readability, and multiply imaginary part with -1
	else {
		out << C.real << " - " << C.imaginary*-1 << "i";
	}

	// Return ostream object
	return out;
}

// Overloaded >> operator
// Makes it possible to use "cin >> ComplexNumberObject"
// Prompting must be handled during the function call
std::istream& operator>>(std::istream& in, ComplexNumber& C)
{
	in >> C.real >> C.imaginary;
	return in;
}


