#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student
{
private:
	const int nrMatricol;
	string nume;
	int nrNote;
	int* note;
	float soldCont;

public:

	Student() : nrMatricol(0)
	{
		nume = "NA";
		nrNote = 0;
		note = NULL;
		soldCont = 0;
	}

	Student(string _nume, int _nrNote, int* _note, int _nrMatricol, float _soldCont) 
		: nume(_nume), nrMatricol(_nrMatricol), soldCont(_soldCont)
	{
		if (_note != NULL && _nrNote != 0)
		{
			note = new int[_nrNote];
			nrNote = _nrNote;
			for (int i = 0; i < nrNote; i++)
				note[i] = _note[i];
		}
		else
		{
			note = NULL;
			nrNote = 0;
		}
	}

	Student(const Student& s) :nume(s.nume), nrMatricol(s.nrMatricol), soldCont(s.soldCont)
	{
		if (s.note != NULL && s.nrNote != 0)
		{
			note = new int[s.nrNote];
			nrNote = s.nrNote;
			for (int i = 0; i < nrNote; i++)
				note[i] = s.note[i];
		}
		else
		{
			note = NULL;
			nrNote = 0;
		}
	}

	Student& operator=(const Student& s)
	{
		nume = s.nume;
		soldCont = s.soldCont;
		if (note) delete[] note;
		if (s.note != NULL && s.nrNote != 0)
		{
			note = new int[s.nrNote];
			nrNote = s.nrNote;
			for (int i = 0; i < nrNote; i++)
				note[i] = s.note[i];
		}
		else
		{
			note = NULL;
			nrNote = 0;
		}
		return *this;
	}
	Student operator+(float sold)
	{
		Student rez = *this;
		rez.soldCont += sold;
		return rez;
	}

	Student& operator+=(float sold)
	{
		soldCont += sold;
		return *this;
	}
	//forma de preincrementare
	Student& operator++()
	{
		soldCont++;
		return *this;
	}
	//forma de postincrementare
	Student operator++(int)
	{
		Student copie = *this;
		soldCont++;
		return copie;
	}
	int& operator[](int index)
	{
		if (index >= 0 && index < nrNote)
			return this->note[index];
		else
			throw exception("index invalid");
	}
	operator string() { return this->nume; }

	explicit operator float() { return this->soldCont; }

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
		if (note) delete[] this->note;
	}

	friend Student operator+(float sold, Student s) { return s + sold; }
};


int main()
{
	int note[] = { 10,4,6 };
	Student s("Gigel", 3, note, 102, 100.5);
	s.afisare();

	Student s2;
	s2 = s + 10.0; 
	s2.afisare();
	s.afisare();

	s2 = 10.0f + s;
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

	int nota = s[1];
	cout << "\nNota: " << nota;

	s[1] = 10;

	string nume = s;


	float sold = (float)s;

	int x, y, z = 2;
	y = 2;
	x = y + 4;
	x = y += z;
	return 0;
}
