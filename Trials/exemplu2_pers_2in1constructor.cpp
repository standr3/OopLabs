#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Pers
{
	int varsta;
	float salariu;
	char nume[20];
public:
	//Pers() // constructor implicit <=> default 
	//{
	//	strcpy(nume, "Anonim");
	//	varsta = 0;
	//	salariu = 0;
	//}

	//Pers(char* n, int v, float s) // constructor cu toti param
	//{
	//	strcpy(nume, n); varsta = v; salariu = s;
	//}

	/* Cei doi constructori pot fi combinati intr-un singur constructor astfel */
	Pers(const char* n = "Anonim", int v = 0, float s = 0)
		: varsta(v), salariu(s)
	{
		strcpy(nume, n);
	}


	char* getNume()
	{
		return nume;
	}

};

int main()
{
	Pers p1;

	cout << p1.getNume();
	return 0;
}
