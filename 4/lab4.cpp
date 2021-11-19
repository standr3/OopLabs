//TO DO TEMA
//de explicat metodele f,f2,f3 si f4. Param, ce returneaza, ce se apeleaza, cum se face transferul param
//ptr clasa TransportPublic, de adaugat atribut string, static, constructor copiere, destructor, lista initializatori

#include<iostream>
using namespace std;

//string -
//atribut static -
//constructor copiere -
//lista initializatori in constructor -
//destructor -

class Student
{
private:
	//char* nume;
	string nume;
	int nrNote;
	int* note;

public:
	static int nrStudenti;//atribut al clasei, si nu al obiectelor; nu mareste sizeof(obj)
	Student():nume(""),nrNote(0),note(NULL)
	{
		cout << "\nAPEL CONSTR FARA PARAM";
		//this->nume = "";
		//this->nrNote = 0;
		//this->note = NULL;
		nrStudenti++;
	}

	Student(string nume, int nrNote, int* note):nume(nume)
	{
		cout << "\nAPEL CONSTR CU PARAM";
		//this->nume = nume;
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
		nrStudenti++;
	}

	Student(const Student& s):nume(s.nume)
	{
		cout << "\nAPEL CONSTR COPIERE";
		//this->nume = s.nume;
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
		nrStudenti++;
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

	~Student()
	{
		cout << "\nAPEL DESTRUCTOR";
		//if (this->note != NULL)
			delete[] this->note;
	}
};

//initializare atribut static al clasei Student
int Student::nrStudenti = 0;

void f(Student s)
{
	//to do
}

void f2(Student& s)
{

}

Student f3(Student vs[10])
{
	return vs[0];
}

Student& f4()
{
	Student s;
	return s;
}

int main()
{
	int note[] = { 9,4 };
	Student s;
	Student s2("Gigel", 3, new int[] {4, 8, 9});
	Student s3("Costel", 2, note);
	s.afisare();
	s2.afisare();
	s3.afisare();
	//versiunea default de copy constr implica shallow copy, nu face alocare de zona de memorie
	Student s4(s2);//apel constructor de copiere 
	s4.afisare();
	cout << endl<<Student::nrStudenti;

	Student* ps = new Student();//1 ori constructor fara param
	Student vs[10];//10 ori constructor fara param
	Student* ps2 = new Student[10];//10 ori constructor fara param
	Student listaStudenti[] = { s,s2,s3 };//3 ori copy constr
	//TO DO: de facut dezalocari ptr variabilele ps, vs,ps2, listaStudenti, daca este nevoie, pentru evitate memory leaks
	delete ps;//destructor de 1 ori
	delete[] ps2;//destructor de 10 ori

	cout << "\n*******************************";
	f(s);
	cout << "\n*******************************";
	f2(s);
	cout << "\n*******************************";
	Student s5=f3(vs);
	cout << "\n*******************************";
	Student s6 = f4();
	cout << "\n*******************************";
	return 0;
}
