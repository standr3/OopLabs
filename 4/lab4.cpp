#include<iostream>
using namespace std;

class Student
{
private:
	//char* nume;
	string nume;
	int nrNote;
	int* note;

public:
	static int nrStudenti;
	Student()
	{
		nume = "NA";
		nrNote = 0;
		note = NULL;

		++nrStudenti;
	}
	Student(string _nume, int _nrNote, int* _note)
	{
		nume = _nume;
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

		++nrStudenti;
	}
	Student(const Student& s)
	{
		nume = s.nume;
		if (s.note > 0 && note != NULL)
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
		++nrStudenti;
	}

	~Student()
	{
		if (note) delete[] note;
		nrStudenti--;
	}
	void afisare()
	{
		cout << "Studentul " << this->nume << " are " << this->nrNote << " note: ";
		if (this->note != NULL)
		{
			for (int i = 0; i < this->nrNote; i++)
				cout << this->note[i] << " ";
		}
		else
			cout << "-";
		cout << endl;
	}

};
int Student::nrStudenti = 0;

int main()
{
	int note[] = { 9,4 };
	Student s;
	Student s2("Gigel", 3, new int[] {4, 8, 9});
	Student s3("Costel", 2, note);
	s.afisare();
	s2.afisare();
	s3.afisare();
	
	Student s4(s2);
	s4.afisare();
	cout << endl << Student::nrStudenti;

	Student* ps = new Student();
	Student vs[10];
	Student* ps2 = new Student[10];
	Student listaStudenti[] = { s,s2,s3 };

	delete ps;
	delete[] ps2;
	return 0;
}
