#pragma once

/**
 * Scope illustrates variable scope - e.g. within a code section {}, within a class, within a file
 * Three versions of globalVar
 *   Scope class member variable - initialized to 100 (see below in this header file)
 *   Scope class method (showScope) local variable - inialized to 999
 *   Outside Scope class (but inside scope.cpp) - initialized to 500.
 */

class Scope
{
private:
	int globalVar = 100;

public:
	Scope();               // empty constructor - if called, globalVar = 100 (default in the .h file)
	Scope(int gVar);       // constructor initializing globalVar to gVar parameter value
	void showScope();      //  illustrates local variable scope (based on braces) &  class member variable vs. variables declared inside a .cpp file ...
	void showGlobalScope();  // outputs class member globalVar

	// showFileScope() an additional routine defined in scope.cpp but is NOT part of the Scope class, hence not declared here
};

