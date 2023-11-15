#include "ComplexNumber.h"
#include <string>

using namespace std;
int main()
{
	ComplexNumber C0;
	ComplexNumber C1(10, -2);
	ComplexNumber C2(-20, -5);
	ComplexNumber C3(C1);
	ComplexNumber C4(C2);
	ComplexNumber C5(C1);
	ComplexNumber C6;

	cout << "C1: "; C1.printComplexNumber(); cout << endl;
	cout << "C2: "; C2.printComplexNumber(); cout << endl << endl;

	cout << "C1.real = " << C1.getReal() << endl;
	cout << "C1.imaginary = " << C1.getImaginary() << endl;
	cout << "C2.real = " << C2.getReal() << endl;
	cout << "C2.imaginary = " << C2.getImaginary() << endl << endl;

	cout << "C1 + C2 = "; (C1 + C2).printComplexNumber(); cout << endl;
	cout << "C1 - C2 = "; (C1 - C2).printComplexNumber(); cout << endl;
	cout << "C1 * C2 = "; (C1 * C2).printComplexNumber(); cout << endl;
	cout << "C1 / C2 = "; (C1 / C2).printComplexNumber(); cout << endl << endl;

	cout << "Modulus of C1 = " << C1.modulus() << endl;
	cout << "Modulus of C2 = " << C2.modulus() << endl;

	cout << "C1 > C2 : " << ((C1 > C2) ? "true" : "false") << endl;
	cout << "C1 < C2 : " << ((C1 < C2) ? "true" : "false") << endl << endl;

	cout << "Copy of C1 (C3): "; C3.printComplexNumber(); cout << endl;
	cout << "C1 >= C2 : " << ((C1 >= C2) ? "true" : "false") << endl;
	cout << "C1 <= C2 : " << ((C1 <= C2) ? "true" : "false") << endl; 
	cout << "C1 <= C3 : " << ((C1 <= C3) ? "true" : "false") << endl;
	cout << "C1 >= C3 : " << ((C1 >= C3) ? "true" : "false") << endl << endl;

	cout << "Copy of C1 (C3): "; C3.printComplexNumber(); cout << "		| Used copy constructor on C1 to duplicate it." << endl;
	cout << "C3 += C2 = "; (C3 += C2).printComplexNumber(); cout << endl;
	cout << "C3 = "; C3.printComplexNumber(); cout << endl << endl;

	cout << "Copy of C2 (C4): "; C4.printComplexNumber(); cout << "		| Used copy constructor on C2 to duplicate it." << endl;
	cout << "C2 -= C1 = "; (C4 -= C1).printComplexNumber(); cout << endl;
	cout << "C4 = "; C4.printComplexNumber(); cout << endl << endl;

	cout << "C3 *= C4 = "; (C3 *= C4).printComplexNumber(); cout << endl;
	cout << "C3 = "; C3.printComplexNumber(); cout << endl << endl;

	cout << "C6 = C4 = "; (C6 = C4).printComplexNumber(); cout << "		| Used assign operator to set C6's value equal to C4." << endl;
	cout << "C0: "; C0.printComplexNumber(); cout << endl;
	cout << "C6 /= C0 = "; (C6 /= C0).printComplexNumber(); cout << endl;
	cout << "C6 = "; C6.printComplexNumber(); cout << "		| After division by zero, C6 has been set to zero." << endl << endl;

	cout << "C4: "; C4.printComplexNumber(); cout << endl;
	cout << "C4 /= C1 = "; (C4 /= C1).printComplexNumber(); cout << endl;
	cout << "C4: "; C4.printComplexNumber(); cout << endl << endl;

	cout << "C4++ = "; C4++.printComplexNumber(); cout << endl;
	cout << "C4-- = "; C4--.printComplexNumber(); cout << endl << endl;

	cout << "C0 ?= 0 : " << ((C0.isZero()) ? "true" : "false") << endl;
	cout << "C1 ?= 0 : " << ((C1.isZero()) ? "true" : "false") << endl << endl;

	ComplexNumber C7(1, 1);

	// Can use dot operator consecutively.
	C7.setReal(2).setImaginary(2).printComplexNumber(); cout << endl;
	cout << "Size of C7: " << C7.size() << endl << endl;

	cout << "C1: " << C1 << " C2: " << C2 << " C3: " << C3 << " C4: " << C4 << " C5: " << C5 << " C6: " << C6 << " C7: " << C7 << endl << endl;

	ComplexNumber C8;
	cout << "Enter Complex Number (Real Imaginary): ";
	cin >> C8;
	cout << C8 << endl;
	cout << "C8 imaginary: " << C8.getImaginary() << endl << endl;

	ComplexNumber C9 = C8.getConjugate();
	cout << "Conjugate of " << C8 << " is " << C9 << endl;

	return 0;
}