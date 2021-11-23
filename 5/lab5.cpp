#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class CustomException
{
	string mesaj;
public:
	CustomException(string mesaj)
	{
		this->mesaj = mesaj;
	}

	string getMesaj()
	{
		return this->mesaj;
	}
};

enum Facultate
{
	CSIE = 1, MK = 2, FABIZ = 3, OTHER = 4
};

class Student
{
private:

	string nume;
	int nrNote;
	int* note;
	const int nrMatricol;
	Facultate facultate;
	static int DimensiuneMinSir;//atribut folosit pentru validare

public:
	Student() : nrMatricol(0)
	{
		nume = "NA";
		nrNote = 0;
		note = NULL;
		facultate = Facultate::CSIE;
	}
	Student(string _nume, int _nrNote, int* _note, int _nrMatricol,
		Facultate _facultate) : nrMatricol(_nrMatricol)
	{
		if (_nume.length() >= DimensiuneMinSir)
			nume = _nume;
		else
			nume = "NA";

		if (_nrNote > 0 && _note != NULL)
		{
			nrNote = _nrNote;
			note = new int[nrNote];
			for (int i = 0; i < nrNote; ++i)
			{
				note[i] = _note[i];
			}
		}
		else
		{
			nrNote = 0;
			note = NULL;
		}
		facultate = _facultate;
	}
	Student(const Student& s) : nrMatricol(s.nrMatricol)
	{
		if (s.nume.length() >= DimensiuneMinSir)
			nume = s.nume;
		else
			nume = "NA";

		if (s.nrNote > 0 && s.note != NULL)
		{
			nrNote = s.nrNote;
			note = new int[nrNote];
			for (int i = 0; i < nrNote; ++i)
			{
				note[i] = s.note[i];
			}
		}
		else
		{
			nrNote = 0;
			note = NULL;
		}
		facultate = s.facultate;
	}

	~Student()
	{
		if (note) delete[] note;
	}

	Student& operator=(const Student& s)
	{
		nume = s.nume;
		facultate = s.facultate;
		if (note) delete[] note;
		if (s.note != NULL && s.nrNote != 0)
		{
			nrNote = s.nrNote;
			note = new int[nrNote];
			for (int i = 0; i < nrNote; ++i)
				note[i] = s.note[i];
		}
		else
		{
			note = NULL;
			nrNote = 0;
		}
		return *this;
	}
	void afisare()
	{
		cout << "Studentul " << this->nume << ", nr matricol: " << this->nrMatricol;
		cout << ", facultate: " << this->facultate;
		cout << " are " << this->nrNote << " note: ";
		if (this->note != NULL)
			for (int i = 0; i < this->nrNote; i++)
				cout << this->note[i] << " ";
		else
			cout << "-";
		cout << endl;
	}
	int getNota(int i)
	{
		if (this->note != NULL && i >= 0 && i < this->nrNote)
			return this->note[i];
		else
			throw exception("nota nu s-a putut extrage");
	}
	void setNume(string _nume)
	{
		if (nume.length() >= Student::DimensiuneMinSir)
			this->nume = _nume;
		else
			throw new CustomException("dimensiune sir prea mica");
	}
};

int Student::DimensiuneMinSir = 1;

int main()
{
	int note[] = { 10,5,3 };
	Student s("Gigel", 3, note, 1002, Facultate::CSIE);
	Student s2;
	s.afisare();
	Student s3(s2);

	s2 = s;
	s3 = s2 = s;

	s2.afisare();

	try
	{
		int nota;
		nota = s.getNota(10);
		cout << endl << nota;
	}
	catch (exception ex)
	{
		cout << endl << ex.what() << endl;
	}

	try
	{
		s.setNume("Cici");
		s.afisare();
	}
	catch (CustomException* ex)
	{
		cout << endl << ex->getMesaj() << endl;
	}
	return 0;
}
