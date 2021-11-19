#include<iostream>
using namespace std;

//implementare clasa; constructor fara param; cu toti param;
//metoda de afisare; metode tip accesor (get si set)

//TEMA
class TichetTransport
{
private:
	char* sistemTransportPublic; //metrou sau STB sau ...
	bool esteAbonament; //true sau false
	int nrCalatorii;
	int nrLuni;
	int* istoricCalatorii;//istoricul nr de calatorii pentru ultimele nrLuni luni
	char numeUtilizator[100];

public:
	//TO DO
	//constructor fara param
	//constructor cu param
	//constructor cu mai putini parametri
	//metoda afisare
	// metode accesor pentru fiecare atribut privat
};

class Produs
{
	//private; protected; public
	char* denumire;
	int nrPreturi;
	float* istoricPreturi;
	char unitateMasura[20];
	int stoc;
public:
	bool estePerisabil;

	Produs()//constructor fara parametri
	{
		//rol: alocare zona memorie + initializare
		this->denumire = NULL;
		this->nrPreturi = 0;
		this->istoricPreturi = NULL;
		strcpy(this->unitateMasura, "NA");
		this->stoc = 0;
		this->estePerisabil = true;
	}

	Produs(char* denumire, int nrPreturi, float* istoricPreturi, char* unitateMasura, int stoc, bool estePerisabil)
	{
		if (denumire != NULL)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
			this->denumire = NULL;
		if (istoricPreturi != NULL && nrPreturi != 0)
		{
			this->nrPreturi = nrPreturi;
			//1 deep copy
			this->istoricPreturi = new float[nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->istoricPreturi[i] = istoricPreturi[i];
			//2 shallow copy
			//this->istoricPreturi = istoricPreturi; DO NOT
			//3 DO NOT
			//this->istoricPreturi = new float[nrPreturi];
			//this->istoricPreturi = istoricPreturi;
		}
		else
		{
			this->istoricPreturi = NULL;
			this->nrPreturi = 0;
		}
		if (unitateMasura != NULL)
		{
			strcpy(this->unitateMasura, unitateMasura);
		}
		else
			strcpy(this->unitateMasura, "NA");
		this->stoc = stoc;
		this->estePerisabil = estePerisabil;
	}

	Produs(char* denumire, int stoc)
	{
		if (denumire != NULL)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
			this->denumire = NULL;
		this->stoc = stoc;
		//nu uitam si de celelalte atribute
		this->nrPreturi = 0;
		this->istoricPreturi = NULL;
		this->estePerisabil = true;
		strcpy(this->unitateMasura, "NA");
	}

	void afisare() {
		cout << "Denumire: ";
		if (this->denumire == NULL) {
			cout << "Anonim" << endl;
		}
		else {
			cout << this->denumire << endl;
		}
		cout << "Stoc: " << this->stoc << endl;
		cout << "Este perisabil: ";
		if (this->estePerisabil == true) {
			cout << "DA" << endl;
		}
		else {
			cout << "NU" << endl;
		}
		cout << "Unitate de masura: " << this->unitateMasura << endl;
		cout << "Istoric Preturi: ";
		if (this->nrPreturi == 0)
			cout << "Fara istoric preturi";
		else
		{
			for (int i = 0; i < this->nrPreturi; i++) {
				cout << this->istoricPreturi[i] << " ";
			}
		}
		cout << endl;
	}

	//metode accesor de tip get si set
	//atribut denumire
	void setDenumire(const char* denumire)
	{
		//obj this deja exista
		delete[] this->denumire;//pentru a evita memory leaks(zona de memorie alocata care nu a fost dezalocata)
		if (denumire != NULL)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
			this->denumire = NULL;
	}

	char* getDenumire()
	{
		return this->denumire;
	}

};

int main()
{
	char denumire[] = "Biscuit";
	float preturi[] = { 12.4, 12, 15, 14.5 };
	char unitateMasura[] = "Buc";
	Produs p;//constructor default
	//sizeof(p)
	Produs p2(denumire, 4, preturi, unitateMasura, 125, false);//constructor cu toti parametri
	p.afisare();
	p2.afisare();
	Produs p3(denumire, 10);
	//modificari pe obiecte
	//ptr atribute public
	p3.estePerisabil = false;
	cout << endl << p3.estePerisabil;
	//ptr atribute private
	p3.setDenumire("Biscuitel");
	cout << endl<<p3.getDenumire();
	return 0;
}
