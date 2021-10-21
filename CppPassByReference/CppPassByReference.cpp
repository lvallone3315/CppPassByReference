// CppPassByReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swap(int, int);
void swapByReference(int&, int&);

int main()
{
    std::cout << "Hello World!\n";

    int a2 = 2;
    int b3 = 3;


    swap(a2, b3);
    std::cout << "Main: a = " << a2 << "\tb = " << b3 << "\n\n\n";

    // swapByReference(a2, b3);
    // std::cout << "Main: a = " << a2 << "\tb = " << b3 << "\n";
}

void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout << "Swap: a = " << a << "\tb = " << b << "\n";
}

void swapByReference(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout << "Swap: a = " << a << "\tb = " << b << "\n";
}
