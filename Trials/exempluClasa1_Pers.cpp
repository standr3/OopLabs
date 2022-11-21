#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Pers
{
private: // eticheta private poate lipsi deoarece se subintelege
	int varsta;
protected:
	float salariu;
public:
	char nume[20];


	void init(const char* n = "Anonim", int v = 0, float s = 0.)
	{
		strcpy(nume, n); varsta = v; salariu = s;
	}

	char* getNume();

	int getVarsta() 
	{ 
		return varsta; 
	}
};


// Definire in afara clasei
char* Pers::getNume() {
	return nume; 
}

int main() 
{
	Pers p1;
	p1.init(); // daca nu dam parametri vom initializa cu valori implicite;

	cout << "Nume p1: " << p1.getNume() << endl;
	cout << "Varsta p1: " << p1.getVarsta() << endl;
	return 0;
}
