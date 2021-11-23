#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Produs
{
	char* denumire;
	int nrPreturi;
	float* istoricPreturi;
	char unitateMasura[20];
	int stoc;
public:
	bool estePerisabil;
	Produs()
	{
		this->denumire = NULL;
		this->nrPreturi = 0;
		this->istoricPreturi = NULL;
		strcpy(unitateMasura, "NA");
		this->stoc = 0;
		this->estePerisabil = false;
	}
	Produs(char* _denumire, int _nrPreturi, float* _istoricPreturi, char* _unitateMasura, int _stoc,
		bool _estePerisabil)
	{
		if (_denumire)
		{
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		else
		{
			this->denumire = NULL;
		}

		if (_nrPreturi > 0 && _istoricPreturi != NULL)
		{
			this->nrPreturi = _nrPreturi;
			this->istoricPreturi = new float[this->nrPreturi + 1];
			for (int i = 0; i < this->nrPreturi; i++)
			{
				this->istoricPreturi[i] = _istoricPreturi[i];
			}
		}
		else
		{
			this->nrPreturi = 0;
			this->istoricPreturi = NULL;
		}

		if (_unitateMasura)
		{
			strcpy(this->unitateMasura, _unitateMasura);
		}
		else
		{
			strcpy(this->unitateMasura, "NA");
		}

		this->stoc = _stoc;
		this->estePerisabil = _estePerisabil;
	}
	Produs(const Produs& p)
	{
		if (p.denumire)
		{
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		else
		{
			this->denumire = NULL;
		}

		if (p.nrPreturi > 0 && p.istoricPreturi != NULL)
		{
			this->nrPreturi = p.nrPreturi;
			this->istoricPreturi = new float[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
			{
				this->istoricPreturi[i] = p.istoricPreturi[i];
			}
		}
		else {
			this->nrPreturi = 0;
			this->istoricPreturi = NULL;
		}
		if (p.unitateMasura)
		{
			strcpy(this->unitateMasura, p.unitateMasura);
		}
		else
		{
			strcpy(this->unitateMasura, "NA");
		}
		this->stoc = p.stoc;
		this->estePerisabil = p.estePerisabil;
	}
	~Produs()
	{
		if (this->denumire) delete[] this->denumire;
		if (this->istoricPreturi) delete[] this->istoricPreturi;
	}
	friend ostream& operator<< (ostream& os, Produs& p)
	{
		if (p.denumire != NULL)
		{
			os << "Denumire: " << p.denumire << "; ";
		}
		os << "NrPreturi: " << p.nrPreturi;
		if (p.nrPreturi > 0 && p.istoricPreturi != NULL) 
		{
			os << "; Preturi";
			for (int i = 0; i < p.nrPreturi; ++i)
			{
				os << p.istoricPreturi[i] << ", ";
			}
		}
		os << "; UnitateMasura: "	<< p.unitateMasura;
		os << "; Stoc: "			<< p.stoc;
		os << "; EstePerisabil: "	<< p.estePerisabil;
		return os;
	}
	/*friend istream& operator>> (istream& is, Produs& p)
	{
		cout << "Denumire: "; is >> p.denumire;
		cout << "NrPreturi: "; is >> p.nrPreturi;

		if (p.istoricPreturi) delete[] p.istoricPreturi;

		if (p.nrPreturi > 0) 
		{
			p.istoricPreturi = new float[p.nrPreturi];
			cout << "Preturi: \n";
			for (int i = 0; i < p.nrPreturi; ++i)
			{
				cout << "[" << i << "]"; is >> p.istoricPreturi[i];
			}
		}
		else
		{
			p.nrPreturi = 0;
			p.istoricPreturi = NULL;
		}
		cout << "UnitateMasura: "; is >> p.unitateMasura;
		cout << "Stoc: "; is >> p.stoc;
		cout << "EstePerisabil: "; is >> p.estePerisabil;
		return is;
	}*/
	void setDenumire(const char* _denumire) 
	{
		if (denumire) delete[] denumire;

		if (_denumire) 
		{
			denumire = new char[strlen(_denumire) + 1];
			strcpy(denumire, _denumire);
		}
		else
		{
			denumire = NULL;
		}
	}
	char* getDenumire() { return denumire; }
	
};

int main()
{
	char denumire1[] = "Biscuit";
	float preturi1[] = { 12.4, 12, 15, 14.5 };
	char unitateMasura[] = "Buc";
	
	Produs p1; 
	Produs p2(denumire1, 4, preturi1, unitateMasura, 125, false);
	
	cout << p1 << endl;
	cout << p2 << endl;

	Produs p3;
	p3.setDenumire(denumire1);
	p3.estePerisabil = false;
	cout << p3.getDenumire() << endl;
	cout << p3 <<endl;
	/*cin >> p3;*/
	cout << endl << p3;
	return 0;
}
