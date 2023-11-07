#pragma once
class Scope
{
private:
	int globalVar = 100;

public:
	Scope();
	Scope(int gVar);
	void showScope();
	void showGlobalScope();
};

