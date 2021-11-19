#include<iostream>
using namespace std;

//TO DO OPTIONAL
//cum facem astfel incat sa nu se afiseze codurile numerice(1,2,3,4) in loc de CSIE,MK,FABIZ,OTHER
//TO DO OPTIONAL 2
//de analizat try catch + exception pe constructori

//TO DO TEMA:
//De analizat cazurile testate in main pentru functiile f5 si f6
//pemntru clasa StudentNou de implementat constructori, operator=, destructor, meth afisare
//atribut constant, static, utilizare try-catch cu CustomException

enum Disciplina
{
	Matematica = 1, Programare=2, Economie=3, LimbiStraine=4
};

class StudentNou
{
	string nume;
	int nrNote;
	int* note;
	Disciplina* discipline;
};



//atribut constant + alt exemplu de static -
//enum - 
//operator =
//try catch + exception - 

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

	Student() :nume("NA"), nrNote(0), note(NULL), nrMatricol(0), facultate(Facultate::OTHER)
	{
		cout << "\nAPEL CONSTR FARA PARAM";
		//this->nume = "NA";
		//this->nrNote = 0;
		//this->note = NULL;
	}

	Student(string nume, int nrNote, int* note, int nrMatricol, Facultate facultate) :nume(nume), nrMatricol(nrMatricol)
	{
		cout << "\nAPEL CONSTR CU PARAM";
		this->facultate = facultate;
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

	Student(const Student& s) :nume(s.nume), nrMatricol(s.nrMatricol),facultate(s.facultate)
	{
		cout << "\nAPEL CONSTR COPIERE";
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

	Student& operator=(const Student& s)//s-ul este rightValue din apel op =; this-ul este leftValue din apel op =
	{
		//comportament "similar" cu copy constructor
		//obj this deja exista
		//atentie la memory leaks
		//in op= nu se gestioneaza atribute constante

		cout << "\nAPEL OPERATOR =";
		this->nume = s.nume;
		this->facultate = s.facultate;
		delete[] this->note;//atentie la memory leaks
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
			throw exception("nota nu s-a putut extrage");//arunca un obj de tip exception; s-a apelat const cu param din clasa exception
	}

	void setNume(string nume)
	{
		if (nume.length() >= Student::DimensiuneMinSir)
			this->nume = nume;
		else
			throw new CustomException("dimensiune sir prea mica");//arunc un pointer la obj de tip CustomException
	}

	~Student()
	{
		cout << "\nAPEL DESTRUCTOR";
		//if (this->note != NULL)
		delete[] this->note;
	}

};

Student& f5(Student v[10])
{
	return v[0];
}

Student f6(Student v[10])
{
	return v[0];
}

int Student::DimensiuneMinSir = 5;


int main()
{
	int note[] = { 10,5,3 };
	Student s("Gigel", 3, note, 1002, Facultate::CSIE);
	Student s2;
	s.afisare();
	Student s3(s2);

	//supraincarcarea operatorilor
	s2 = s;//apel operator de atribuire (Student = Student) (this-ul o sa fie leftValue(s2), iar un obj de tip student este trimis ca param ( rightvalue))
	//forma explicita a apelului op=
	//s2.operator=(s);
	s3 = s2 = s;//apel in cascada a op=

	//1. ce tip de operator este? (binar sau unar)
	//2. tipul operanzilor
	//3. daca primul operand este de tipul clasei, atunci are this, si atunci se poate implementa in clasa
	s2.afisare();
	
	try
	{
		int nota;
		nota = s.getNota(10);//arunca obj de tip exception
		cout << endl << nota;
	}
	catch (exception ex)//in catch prindeti ce arunca metodele apelate in try
	{
		//de regula, venim cu mesaje
		cout << endl << ex.what();
	}

	try
	{
		s.setNume("Cici");
		s.afisare();
	}
	catch (CustomException* ex)
	{
		cout << endl << ex->getMesaj();
	}

	Student v[10];
	cout << "\n*********************************";
	Student s5 = f5(v);
	cout << "\n*********************************";
	Student s6 = f6(v);
	cout << "\n*********************************";
	Student s7;
	s7 = f5(v);
	cout << "\n*********************************";
	Student s8;
	s8 = f6(v);
	cout << "\n*********************************";
	return 0;
}
