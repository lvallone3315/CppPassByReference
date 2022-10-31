// CppPassByReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Scope.h"

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
    std::cout << "\t\tSwap Program Demonstrating C++ Pass by Value & Pass by Reference!\n\n";

    std::cout << "\n\t First two scenarios: pass integer vars by value, then by reference\n";
    std::cout << "\t Second two scenarios: pass an object of type TwoInts by value, then by reference\n\n\n";
    std::cout << "\tC++ swap by reference, in called function/method add & between type and param name\n";
    std::cout << "\t\tfor example: swap(int a, int b) vs. swap (int& a, int& a)\n\n";

    int a2 = 1;
    int b3 = 99;

    TwoInts ab;

    swap(a2, b3);
    std::cout << "\Main swap by values result: \t\t\ta = " << a2 << "\tb = " << b3 << "\n\n";
    system("pause");

    a2 = 1;
    b3 = 99;

    swapByReference(a2, b3);
    std::cout << "\tMain swap result: \t\t\ta = " << a2 << "\tb = " << b3 << "\n";
    system("pause");

    ab.a = 1;
    ab.b = 99;
    swapC(ab);
    std::cout << "\tMain TwoInts swap result: \t\ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");


    ab.a = 1;
    ab.b = 99; 
    swapCByReference(ab);
    std::cout << "\tMain TwoInts Ref swap result: \t\ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");

    ab.a = 1;
    ab.b = 99; 
    ab = swapByNewInstance(ab);
    std::cout << "\tMain TwoInts Instance swap result: \ta = " << ab.a << "\tb = " << ab.b << "\n\n";
    system("pause");

    // Scope section

    std::cout << "\n\nDemonstrate some fundamental variable scope behaviors\n";
    system("pause");

    Scope scope;
    scope.showScope();

    system("pause");
    scope.showGlobalScope();

    extern void showFileScope();  // not part of class, hence not in Scope.h, could declare in Scope.h - but that would be misleading
    showFileScope();
}

// helper functions

void swap(int a, int b) {
    int temp;
    std::cout << "*** Swap two variables: \t\t\ta = " << a << "\tb = " << b << "\n";
    temp = a;
    a = b;
    b = temp;
    std::cout << "  *** Expected Result ***: \t\t\ta = " << a << "\tb = " << b << "\n\n";
}

void swapC(TwoInts numbersToSwap) {
    int temp;
    std::cout << "\n*** Swap twoInts object - by Value*\n";
    temp = numbersToSwap.a;
    numbersToSwap.a = numbersToSwap.b;
    numbersToSwap.b = temp;
}

void swapByReference(int& a, int& b) {
    int temp;

    std::cout << "\n*** Swap two variables - by Reference*\n"; 
    temp = a;
    a = b;
    b = temp;
}

void swapCByReference(TwoInts& numbersToSwap) {
    int temp;
    std::cout << "\n*** Swap twoInts object - by Reference*\n";
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