#include<iostream>
#include"fraction.h"
using namespace std;
/*
Assignment 8
7/13/11

This program uses the fraction class to perform some operations.
It first declares two seperate fractions, and a result fraction. 
It then multiplies,divides, adds and subtracts the fractions together.
It will then test whether or not the fractions are equal. It will then declare two more fractions
and multiply them together. Fractions are always stored in their lowest terms.

*/
int main()
{
     
     fraction f1(9,8);
     fraction f2(2,3);
     fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;
    
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.MultipliedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.DividedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.AddedTo(f2);
    result.print();
    cout << endl;
    
    
    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.Subtract(f2);
    result.print();
    cout << endl;
    
    if (f1.isEqualTo(f2)){
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }
    
    const fraction f3(12, 8);
    const fraction f4(202, 303);
    result = f3.MultipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;

    system("pause");    
}
