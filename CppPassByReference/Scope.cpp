#include "Scope.h"
#include <iostream>
#include <stdio.h>

// Three versions of globalVar
//   Scope class member variable - initialized to 100
//   Scope class method (showScope) local variable - inialized to 999
//   Outside scope class (inside scope.cpp) - initialized to 500

int globalVar = 500;  // should never declare variables here

Scope::Scope() {
	// empty constructor
}

Scope::Scope(int gVar) {
	this->globalVar = gVar;
}

// show Scope, illustrates
//    local variable scope (based on braces)
//    class member variable vs. file declared variables ...
void Scope::showScope() {
	int localVar = 99;

	{
		int localVar = 1;
		std::cout << "\nlocalVar inside braces: " << localVar << "\tmemory address: " << &localVar << "\n";
	}
	std::cout << "localVar outside braces: " << localVar << "\tmemory address: " << &localVar << "\n";

	int globalVar = 999;
	std::cout << "\n\n globalVar overridden inside method: " << globalVar << "\tmemory address: " << &globalVar << "\n";
	std::cout << "  globalVar member variable: " << this->globalVar << "\tmemory address: " << &this->globalVar << "\n";

	// Note - inside a class method, no access to the globalVaR variable (500) defined outside the class (?)
}

// showGlobalScope -> method inside Scope class, displays member variabale (ie 100)
// showFileScope --> method outside scope class, class variable not visible, but file variable is visible
void Scope::showGlobalScope() {
	std::cout << "\n\nglobalVaR from class method: " << globalVar << "\tmemory address: " << &globalVar << "\n";
}

void showFileScope() {
	std::cout << "globalVar from non-class function: " << globalVar << "\tmemory address: " << &globalVar << "\n";
}
