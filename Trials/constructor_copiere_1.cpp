#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Exemplu
{

public:
	int x = 0;
	Exemplu(int a = 0) :x(a) 
	{
		cout << "\n Constructor in clasa";
	}

	Exemplu(Exemplu& e)
	{
		cout << "\n Constructor de copiere";
		x = e.x;
	}
};


int main()
{
	Exemplu e1;
	Exemplu e2;
	Exemplu e3 = e1, e4(e2); // in ambele cazuri este invocat constructorul de copiere

	return 0;
}
