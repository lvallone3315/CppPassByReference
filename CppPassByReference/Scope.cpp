#include "Scope.h"
#include <iostream>
#include <stdio.h>

Scope::Scope() {
	// empty constructor
}

int globalVar = 500;  // should never declare variables here

void Scope::showScope() {
	int localVar = 99;

	{
		int localVar = 1;
		std::cout << "localVar inside braces: " << localVar << "\n";
	}
	std::cout << "localVar outside braces: " << localVar << "\n";

	int globalVar = 999;
	std::cout << "globalVar overridden inside method: " << globalVar << "\n";
}

void Scope::showGlobalScope() {
	std::cout << "globalVaR from class method: " << globalVar << "\n";
}

void showFileScope() {
	std::cout << "globalVar from non-class function: " << globalVar << "\n";
}
