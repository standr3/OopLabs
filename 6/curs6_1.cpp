
#include <iostream>
using namespace std;
class MaiMic
{
public:
	bool operator() (double a, double b)
	{
		return a < b;
	}
};

class Vector
{
private:
	int dim;
	double* pe;
	static double errPoint;
public:
	Vector(int d = 1) : dim(d)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = 0.0;
	}
	Vector(int d, double* v) : dim(d)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = v[i];
	}

	Vector(Vector& src) : dim(src.dim)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
	}

	~Vector() { delete[] pe; }

	Vector& operator=(Vector& src)
	{
		if (pe != src.pe)
		{
			delete[] pe; dim = src.dim;
			pe = new double[dim];
			for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
		}
		return *this;
	}

	double& operator[](int i)
	{
		if (i >= 0 && i < dim)
		{
			return pe[i]; // *(pe+i)
		}
		else
		{
			cerr << "\n Index out of range";
			// throw new exception("\n Index out of range");
			return errPoint;
		}
	}
	Vector& operator+=(double d) // pushBack
	{
		double* aux = pe;
		pe = new double[dim + 1]; 
		for (int i = 0; i < dim; i++) pe[i] = aux[i];
		pe[dim] = d; dim++;
		delete [] aux;
		return *this;
	}
	void sort(MaiMic mm)
	{
		for(int i=0; i<dim-1; i++)
			for (int j=i+1; j<dim; j++)
				if (!mm(pe[i], pe[j]) )
				{
					double aux = pe[i]; pe[i] = pe[j]; pe[j] = aux;
				}
	}

	friend ostream& operator<<(ostream&, Vector&);

};

double Vector::errPoint=0;

ostream& operator<<(ostream& os, Vector& v)
{
	os << endl;
	for (int i = 0; i < v.dim; i++) os << v.pe[i] << "\t";
	return os;
}

int main()
{
	Vector v1;
	double vd[] = { 5.5, 1.2, 7.9, 8.2, 3.5 };
	
	Vector v2(sizeof(vd) / sizeof(vd[0]), vd), v3(10000), v4(v2);
	cout << v1 << v2;
	v2[10] = 10;
	cout << "\n Err: "<< v1[2];
	(v2 += 1.1) += 9.9;  cout << "\nModif+Add " << v2;
	MaiMic maiMic;
	v2.sort(maiMic);
	cout <<"\nSortat: " << v2;

}
