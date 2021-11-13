
#include<iostream>
using namespace std;

//TEMA: pe clasa Masina de implementat: << si >>, op functie ( 2 ex), op comparatie ( 2 ex), !

//! == functie
// << si >>

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
	}

	Student(string nume, int nrNote, int* note, int nrMatricol, float soldCont) :nume(nume), nrMatricol(nrMatricol), soldCont(soldCont)
	{


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

	bool operator> (const Student& s)
	{
		if (this->soldCont > s.soldCont)
			return true;
		return false;
	}

	Student operator!()
	{
		Student rez = *this;
		delete[] rez.note;
		rez.note = NULL;
		rez.nrNote = 0;
		return rez;
	}

	float operator()(int index1, int index2)
	{
		float medie = 0;
		for (int i = index1; i <= index2; i++)
			medie += this->note[i];
		return medie / (index2 - index1 + 1);
	}

	//operator functie care nu primeste alti operanzi fata de this
	float operator()()
	{
		return 0;
	}

	Student operator++(int)
	{
		Student copie = *this;
		delete[] this->note;
		this->nrNote++;
		this->note = new int[this->nrNote];
		for (int i = 0; i < copie.nrNote; i++)
			this->note[i] = copie.note[i];
		this->note[this->nrNote - 1] = copie.note[copie.nrNote - 1];

		return copie;
	}

	Student operator-(int x)
	{
		Student rez = *this;
		delete[] rez.note;
		rez.nrNote -= x;
		rez.note = new int[rez.nrNote];
		for (int i = 0; i < rez.nrNote; i++)
			rez.note[i] = this->note[i + x];
		return rez;
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
		delete[] this->note;
	}

	friend ostream& operator<<(ostream& out, const Student& s);
	friend istream& operator>>(istream& in, Student& s);
};

istream& operator>>(istream& in, Student& s)
{
	cout << "\nIntroduceti nume: ";
	in >> s.nume;
	cout << "\nIntroduceti nr note: ";
	in >> s.nrNote;
	delete[] s.note;
	if (s.nrNote > 0)
	{
		s.note = new int[s.nrNote];
		cout << "\nIntroduceti notele: ";
		for (int i = 0; i < s.nrNote; i++)
			in >> s.note[i];
	}
	else
	{
		s.nrNote = 0;
		s.note = NULL;
	}
	cout << "\nIntroduceti sold cont: ";
	in >> s.soldCont;
	return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << "Studentul " << s.nume << ", nr matricol: " << s.nrMatricol << ", sold cont: " << s.soldCont;
	out << " are " << s.nrNote << " note: ";
	if (s.note != NULL)
		for (int i = 0; i < s.nrNote; i++)
			out << s.note[i] << " ";
	else
		out << "-";
	out << endl;
	return out;
}

int main()
{
	int note[] = { 10,4,6 };
	int note2[] = { 1,2,3,4,5,6,7,8 };
	Student s("Gigel", 3, note, 102, 100.5);
	s.afisare();
	Student s2("Costel", 8, note2, 105, 150);
	s2.afisare();

	if (s > s2)
		cout << "\nStud s are un sold cont > ca s2";
	else
		cout << "\nAltfel";

	Student s3;
	s3 = !s2;
	s3.afisare();
	s2.afisare();
	//SAU
	/*bool ok;
	ok = !s2;*/

	int x, y = 0;
	x = !y;
	cout << "\nx: " << x << " y: " << y;

	float medie = s2(1, 5);//returneaza media notelor studentului intre index1 si index2
	cout << "\nMedie: " << medie;

	//cout << s2;

	//cin >> s2;
	//cout << s2;

	Student s5 = s2++;
	cout << s5 << s2;

	Student s6;
	s6 = s2 - 4;
	cout << s6;
	return 0;
}
