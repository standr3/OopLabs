#include<iostream>
#include<string>
using namespace std;

enum Anotimp
{
	PRIMAVARA=1, VARA=2, TOAMNA=3,IARNA=4
};

ostream& operator<<(ostream& out, Anotimp a)
{
	int cod = a;
	switch (cod)
	{
	case 1:
		out << "Primavara";
		break;
	case 2:
		out << "Vara";
		break;
	case 3:
		out << "Toamna";
		break;
	case 4:
		out << "Iarna";
		break;
	}
	return out;
}

istream& operator>>(istream& in, Anotimp& a)
{
	int cod;
	cout << "Anotimp: ";
	in >> cod;
	switch (cod)
	{
	case 1:
		a = Anotimp::PRIMAVARA;
		break;
	case 2:
		a = Anotimp::VARA;
		break;
	case 3:
		a = Anotimp::TOAMNA;
		break;
	case 4:
		a = Anotimp::IARNA;
		break;
	default:
		a = Anotimp::IARNA;
		break;
	}
	return in;
}

class Excursie
{
	string destinatie;
	Anotimp anotimp;
	float pret;
	string* obiectiveTuristice;
	int nrObiective;

public:
	Excursie()
	{
		this->destinatie = "Anonim";
		this->anotimp = Anotimp::PRIMAVARA;
		this->pret = 0;
		this->obiectiveTuristice = NULL;
		this->nrObiective = 0;
	}

	Excursie(string destinatie, Anotimp anotimp, float pret, string* obiectiveTuristice, int nrObiective)
	{
		this->destinatie = destinatie;
		this->anotimp = anotimp;
		this->pret = pret;
		if (nrObiective != 0 && obiectiveTuristice != NULL)
		{
			this->nrObiective = nrObiective;
			this->obiectiveTuristice = new string[this->nrObiective];
			for (int i = 0; i < this->nrObiective; i++)
				this->obiectiveTuristice[i] = obiectiveTuristice[i];
		}
		else
		{
			this->obiectiveTuristice = NULL;
			this->nrObiective = 0;
		}
	}

	Excursie(const Excursie& e)
	{
		this->destinatie = e.destinatie;
		this->anotimp = e.anotimp;
		this->pret = e.pret;
		if (e.nrObiective != 0 && e.obiectiveTuristice != NULL)
		{
			this->nrObiective = e.nrObiective;
			this->obiectiveTuristice = new string[this->nrObiective];
			for (int i = 0; i < this->nrObiective; i++)
				this->obiectiveTuristice[i] = e.obiectiveTuristice[i];
		}
		else
		{
			this->obiectiveTuristice = NULL;
			this->nrObiective = 0;
		}
	}

	Excursie& operator=(const Excursie& e)
	{
		delete[] this->obiectiveTuristice;
		this->destinatie = e.destinatie;
		this->anotimp = e.anotimp;
		this->pret = e.pret;
		if (e.nrObiective != 0 && e.obiectiveTuristice != NULL)
		{
			this->nrObiective = e.nrObiective;
			this->obiectiveTuristice = new string[this->nrObiective];
			for (int i = 0; i < this->nrObiective; i++)
				this->obiectiveTuristice[i] = e.obiectiveTuristice[i];
		}
		else
		{
			this->obiectiveTuristice = NULL;
			this->nrObiective = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Excursie& e);
	friend istream& operator>>(istream& in, Excursie& e);
};

istream& operator>>(istream& in, Excursie& e)
{
	cout << "\nDestinatie: ";
	//in >> e.destinatie;
	getline(in, e.destinatie, '\n');
	cout << "Anotimp: ";
	in >> e.anotimp;
	cout << "Pret: ";
	in >> e.pret;
	cout << "Nr obiective turistice: ";
	in >> e.nrObiective;
	in.clear();
	delete[] e.obiectiveTuristice;
	if (e.nrObiective > 0)
	{
		e.obiectiveTuristice = new string[e.nrObiective];
		cout << "Obiective turistice: \n";
		for (int i = 0; i < e.nrObiective; i++)
		{
			//in >> e.obiectiveTuristice[i];
			getline(in, e.obiectiveTuristice[i], '\n');
			if(e.obiectiveTuristice[i].empty())
				getline(in, e.obiectiveTuristice[i], '\n');
		}
	}
	else
	{
		e.obiectiveTuristice = NULL;
		e.nrObiective = 0;
	}
	return in;
}

ostream& operator<<(ostream& out, const Excursie& e)
{
	out << "\n----------------------";
	out << "\nDestinatie: " << e.destinatie;
	out << "\nAnotimp: " << e.anotimp;
	out << "\nPret: " << e.pret;
	out << "\nObiective turistice: ";
	if (e.nrObiective != 0 && e.obiectiveTuristice != NULL)
	{
		for (int i = 0; i < e.nrObiective; i++)
			out << e.obiectiveTuristice[i] << ", ";
	}
	else
		out << "-";
	return out;
}

int main()
{
	string* obiective = new string[3];
	obiective[0] = "Piata mare";
	obiective[1] = "Biserica";
	obiective[2] = "Targ Craciun";
	Excursie e("Sibiu", Anotimp::IARNA, 350, obiective, 3);
	cout << e;
	cin >> e;
	cout << e;
	return 0;
}
