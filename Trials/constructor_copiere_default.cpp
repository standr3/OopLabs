#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Pers
{
	int varsta;
public:
	char* pnume;
	Pers(const char* n = "NoName", int v = 0) : varsta(v)
	{
		int sz = strlen(n) + 1;
		pnume = new char[sz];
		strcpy_s(pnume, sz, n);
	}
	int getVarsta() { return varsta; }
};



int main()
{
	Pers* p1 = new Pers("Popescu Ion", 45);
	Pers* p2 = new Pers(*p1); // apel constructor de copiere default
	cout << "\n" << p1->pnume << " are " << p1->getVarsta() << " ani";
	cout << "\n" << p2->pnume << " are " << p2->getVarsta() << " ani";
	strcpy_s(p2->pnume, strlen("Nicula Elena") + 1, "Nicula Elena");
	cout << "\n" << p1->pnume << " are " << p1->getVarsta() << " ani";
	cout << "\n" << p2->pnume << " are " << p2->getVarsta() << " ani";

	//delete p1;	
	//cout << "\n" << p1->pnume << " are " << p1->getVarsta() << " ani";
	//cout << "\n" << p2->pnume << " are " << p2->getVarsta() << " ani";



	return 0;
}
