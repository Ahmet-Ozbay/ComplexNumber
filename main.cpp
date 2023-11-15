#include "include/ComplexNumber.h"
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display Complex Numbers\n";
    cout << "2. Perform Arithmetic Operations\n";
    cout << "3. Calculate Conjugate\n";
    cout << "4. Compare Complex Numbers\n";
    cout << "5. Increment and Decrement\n";
    cout << "6. Calculate Modulus\n";
    cout << "7. Exit\n";
}

ComplexNumber promptUser(ComplexNumber& A) {
    cout << "Enter complex number (Ex: -4.2 2.6): ";
    cin >> A;

    return A;
}

int main() {
    ComplexNumber C0, C1, C2, C3;
    int choice;
    const int w = 14;
    const int w2 = 10;
    char c = 'Y';

    do {
        cout << "******** COMPLEX NUMBERS ********";
        displayMenu();
        cout << "Enter your choice: ";

        // Use a do-while loop to continuously prompt the user until valid input is entered
        do {
            if (!(cin >> choice) || (choice != 7 && (choice < 1 || choice > 6))) {
                cout << "Invalid input. Please enter a valid menu option.\n";

                // Clear any remaining characters in the input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter your choice: ";
            }
        } while (choice != 7 && (choice < 1 || choice > 6));

        switch (choice) {
        case 1:
            promptUser(C1);
            promptUser(C2);
            cout << "C1: " << C1 << endl;
            cout << "C2: " << C2 << endl;
            break;

        case 2:
            cout << "\n--- Arithmetic Operations ---\n";
            cout << "1. Addition (C1 + C2)\n";
            cout << "2. Subtraction (C1 - C2)\n";
            cout << "3. Multiplication (C1 * C2)\n";
            cout << "4. Division (C1 / C2)\n";
            cout << "\nEnter operation choice: ";
            cin >> choice;

           
            cout << "C1: " << C1 << " | C2: " << C2 << endl;
            cout << "Would you like to enter new Complex Numbers? (Y/N): ";
            cin >> c;

               
            if (c == 'Y' || c == 'y') {
                promptUser(C1);
                promptUser(C2);
            }

            switch (choice)
            {
            case 1:
                cout << "C1 + C2 = " << (C1 + C2) << endl;
                break;
            case 2:
                cout << "C1 - C2 = " << (C1 - C2) << endl;
                break;
            case 3:
                cout << "C1 * C2 = " << (C1 * C2) << endl;
                break;
            case 4:
                cout << "C1 / C2 = " << (C1 / C2) << endl;
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }

            break;

        case 3:
            cout << "\n--- Conjugate Finder ---\n";
            promptUser(C3);

            cout << "Conjugate of (" << C3 << ") is: " << C3.getConjugate() << endl;
            break;

        case 4:
            cout << "\n--- Compare Complex Numbers ---\n";
            cout << "C1: " << C1 << " | C2: " << C2 << endl;
            cout << "Would you like to enter new Complex Numbers? (Y/N): ";
            cin >> c;

            if (c == 'Y' || c == 'y') {
                promptUser(C1);
                promptUser(C2);
            }
            cout << endl;
            cout << right << setw(w) << "Comparison" << setw(2) <<"|" << "  Result" << endl;
            cout << right << setw(w) << "C1 == C2" << setw(2) << ":" << left << setw(w2) << ((C1 == C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 != C2" << setw(2) << ":" << left << setw(w2) << ((C1 != C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 > C2" << setw(2) << ":" << left << setw(w2) << ((C1 > C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 < C2" << setw(2) << ":" << left << setw(w2) << ((C1 < C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 >= C2" << setw(2) << ":" << left << setw(w2) << ((C1 >= C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 <= C2" << setw(2) << ":" << left << setw(w2) << ((C1 <= C2) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C1 ?= 0" << setw(2) << ":" << left << setw(w2) << ((C1.isZero()) ? "  true" : "  false") << endl;
            cout << right << setw(w) << "C2 ?= 0" << setw(2) << ":" << left << setw(w2) << ((C2.isZero()) ? "  true" : "  false") << endl;

            break;

        case 5:
            cout << "\n--- Increment & Decrement ---\n";
            cout << "1. C1++\n";
            cout << "2. ++C1\n";
            cout << "3. C1--\n";
            cout << "4. --C1\n\n";

            cout << "Current Value of C1: " << C1 << endl;
            cout << "Would you like to enter a new Complex Number? (Y/N): ";
            cin >> c;

            if (c == 'Y' || c == 'y') {
                promptUser(C1);
            }
            cout << "Enter operation choice: ";
            cin >> choice;
            
            cout << "Current Value of C1: " << C1 << endl;
            if (choice == 1) {
                C1++;
                cout << "After incrementing C1: " << C1 << endl;
            }
            else if (choice == 2) {
                ++C1;
                cout << "After incrementing C1: " << C1 << endl;
            }
            else if (choice == 3) {
                C2--;
                cout << "After decrementing C2: " << C2 << endl;
            }
            else if (choice == 4) {
                --C2;
                cout << "After decrementing C1: " << C1 << endl;

            }
            else {
                cout << "Invalid choice\n";
            }
            break;

        case 6:
            cout << "\n--- Modulus Calculator ---\n";
            promptUser(C1);
            cout << "Modulus of (" << C1 << ")= " << C1.modulus() << endl;
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
