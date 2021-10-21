// CppPassByReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class TwoInts {
public:
    int a;
    int b;
}; 

void swap(int, int);
void swapC(TwoInts);
void swapByReference(int&, int&);
void swapCByReference(TwoInts&);
TwoInts swapByNewInstance(TwoInts);



int main()
{
    std::cout << "\t\tSwap Program Demonstrating C++ Pass by Value & Pass by Reference!\n\n\n";

    int a2 = 1;
    int b3 = 99;

    TwoInts ab;

    swap(a2, b3);
    std::cout << "\tActual: \ta = " << a2 << "\tb = " << b3 << "\n\n";
    system("pause");

    a2 = 1;
    b3 = 99;

    swapByReference(a2, b3);
    std::cout << "\tMain: \t\t\ta = " << a2 << "\tb = " << b3 << "\n";
    system("pause");

    ab.a = 1;
    ab.b = 99;
    swapC(ab);
    std::cout << "\tMain TwoInts: \t\ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");


    ab.a = 1;
    ab.b = 99; 
    swapCByReference(ab);
    std::cout << "\tMain TwoInts Ref: \ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");

    ab.a = 1;
    ab.b = 99; 
    ab = swapByNewInstance(ab);
    std::cout << "\tMain TwoInts Instance: \ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");
}

void swap(int a, int b) {
    int temp;
    std::cout << "*** Two Variables passed in: \t\ta = " << a << "\tb = " << b << "\n";
    temp = a;
    a = b;
    b = temp;
    std::cout << "  *** Expected Result ***: \t\ta = " << a << "\tb = " << b << "\n";
}

void swapC(TwoInts numbersToSwap) {
    int temp;
    std::cout << "\n*** TwoInts instance passed in - by Value*\n";
    temp = numbersToSwap.a;
    numbersToSwap.a = numbersToSwap.b;
    numbersToSwap.b = temp;
}

void swapByReference(int& a, int& b) {
    int temp;

    std::cout << "\n*** Two variables passed in - by Reference*\n"; 
    temp = a;
    a = b;
    b = temp;
}

void swapCByReference(TwoInts& numbersToSwap) {
    int temp;
    std::cout << "\n*** TwoInts instance passed in - by Reference*\n";
    temp = numbersToSwap.a;
    numbersToSwap.a = numbersToSwap.b;
    numbersToSwap.b = temp;
}


// Create a new instance of TwoInts and return to calling routine
// Note: Pretty sure this is NO GOOD - since new instance probably created on the stack
TwoInts swapByNewInstance(TwoInts numbersToSwap) {
    TwoInts tempTwoInts;

    std::cout << "\n*** Create a new instance of TwoInts and return to calling routine\n";
    tempTwoInts.b = numbersToSwap.a;
    tempTwoInts.a = numbersToSwap.b;
    return tempTwoInts;
}