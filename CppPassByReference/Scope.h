#pragma once
class Scope
{
private:
	int globalVar = 100;

public:
	Scope();
	void showScope();
	void showGlobalScope();
};

