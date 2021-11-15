
#include<iostream>
using namespace std;

//operatori: ++ pre si post,+, +=, cast []

enum TipCarburant
{
	BENZINA, DIESEL, ELECTRIC
};
//TEMA. Ptr clasa Masina: constructori, op=, destructor, meth afisare, supraincarcare op: +, -, /, *, ++, --, [], cast 2 ex, +=, -=
//mentiune: cel putin 3 supraincarcari de op sa realizeze modificari pe dimensiunea vectorului alimentare (seminar 2)
//ex: m2 = m+1 => m2 va detine o alimentare in plus fara de m(se dubleaza ultima alimentare)
//ex2: m2 -= 3;//elimina ultimele 3 alimentari ( puteti adauga exception)
//TEMA OPTIONALA: de implementat un return ptr vectorul alimentare ( safe) ( de tip consultare doar, nu si modificare)
//TEMA OPTIONALA 2: transfer const Masina& m intr-o metoda implementata ofera siguranta totala obj m? Sau pot sa modific pe m intr-o anumita forma


class Masina
{
private:
	string numeProprietar;
	TipCarburant tipCarburant;
	const int anFabricatie;
	int* alimentare; //dim vector este nrAlimentari (nr litri per alimentare)
	int nrAlimentari;
	static int nrMasiniBenzina;
	static int nrMasiniDiesel;
	static int nrMasiniElectric;
	float pretAchizitie;
};

class Student
{
private:
	const int nrMatricol;
	string nume;
	int nrNote;
	int* note;
	float soldCont;

public:

	Student() :nume("NA"), nrNote(0), note(NULL), nrMatricol(0), soldCont(0)
	{
		//cout << "\nAPEL CONSTR FARA PARAM";
	}

	Student(string nume, int nrNote, int* note, int nrMatricol, float soldCont) :nume(nume), nrMatricol(nrMatricol), soldCont(soldCont)
	{

		//cout << "\nAPEL CONSTR CU PARAM";
		if (note != NULL && nrNote != 0)
		{
			this->note = new int[nrNote];
			this->nrNote = nrNote;
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = note[i];
		}
		else
		{
			this->note = NULL;
			this->nrNote = 0;
		}
	}

	Student(const Student& s) :nume(s.nume), nrMatricol(s.nrMatricol), soldCont(s.soldCont)
	{
		//cout << "\nAPEL CONSTR COPIERE";
		if (s.note != NULL && s.nrNote != 0)
		{
			this->note = new int[s.nrNote];
			this->nrNote = s.nrNote;
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
		else
		{
			this->note = NULL;
			this->nrNote = 0;
		}
	}


	Student& operator=(const Student& s)
	{
		this->nume = s.nume;
		this->soldCont = s.soldCont;
		delete[] this->note;
		if (s.note != NULL && s.nrNote != 0)
		{
			this->note = new int[s.nrNote];
			this->nrNote = s.nrNote;
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
		else
		{
			this->note = NULL;
			this->nrNote = 0;
		}
		return *this;
	}

	Student operator+(float sold)//this-ul inghite primul operand de tip Student
	{
		Student rez = *this;
		rez.soldCont += sold;
		return rez;
	}

	Student& operator+=(float sold)
	{
		this->soldCont += sold;
		return *this;
	}

	//forma de preincrementare
	Student& operator++()
	{
		//modif obj this
		//returnez obj modificat
		this->soldCont++;
		return *this;
	}

	//forma de postincrementare
	Student operator++(int)
	{
		//returnam obj initial si apoi face modificare pe obj this
		Student copie = *this;
		this->soldCont++;
		return copie;
	}

	int& operator[](int index)
	{
		//de adaugat validari + throw exception
		return this->note[index];
	}

	//cast la string
	operator string()
	{
		return this->nume;
	}

	//conversia se va face doar la cerere prin explicit
	explicit operator float()
	{
		return this->soldCont;
	}

	void afisare()
	{
		cout << "Studentul " << this->nume << ", nr matricol: " << this->nrMatricol << ", sold cont: " << this->soldCont;
		cout << " are " << this->nrNote << " note: ";
		if (this->note != NULL)
			for (int i = 0; i < this->nrNote; i++)
				cout << this->note[i] << " ";
		else
			cout << "-";
		cout << endl;
	}

	~Student()
	{
		//cout << "\nAPEL DESTRUCTOR";
		//if (this->note != NULL)
		delete[] this->note;
	}

	friend Student operator+(float sold, Student s);
};

Student operator+(float sold, Student s)
{
	/*Student rez = s;
	rez.soldCont += sold;
	return rez;*/

	/*s.soldCont += sold;
	return s;*/

	return s + sold;
}

int main()
{
	//double = student + double 
	int note[] = { 10,4,6 };
	Student s("Gigel", 3, note, 102, 100.5);
	s.afisare();

	Student s2;
	s2 = s + 10.0; //Student + float
	s2.afisare();
	s.afisare();

	s2 = 10.0f + s; //float + Student
	s2.afisare();
	s.afisare();

	s = s2 += 20.0f;
	s2.afisare();

	s = ++s2;
	s.afisare();
	s2.afisare();

	s = s2++;
	s.afisare();
	s2.afisare();

	int nota = s[1];//preia nota de pe poz 1 din vectorul de note al obj s
	cout << "\nNota: " << nota;

	s[1] = 10;//op index care permite si modificare

	string nume = s;//conversie implicita de la Student la string


	float sold = (float)s;//conversie explicita de la Student la float

	int x, y, z=2;
	y = 2;
	x = y + 4;
	x = y += z;

	//P1. identificare tip operator(binar sau unar)
	//P2. identificare operanzi + ce returneaza
	//P3. daca primul operand este de tipul clasei, meth se poate implementa in clasa (exista this)
	//P3'. daca primul operand nu este de tipul clasei, meth se implementeaza in afara clasei

	return 0;
}
