#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pers
{
private:
    const int marca = 100;
    friend ostream& operator<<(ostream& , Pers &);
    static int nrPers;
public:
    char nume[50] = "Noname";  
    static int getNrPers()
    {
        return nrPers;
    }
    Pers(const char* _nume = "Popescu Ion", double _salariu = 2550.)
        : marca(++nrPers), salariu(_salariu)
    {
        strcpy(nume, _nume);
    }

    ~Pers()
    {
        nrPers--;
    }   
protected:
    double salariu = 2350;
};

int Pers::nrPers=0;

ostream& operator<<(ostream& os, Pers & p)
{
    os << p.marca << " - " << p.nume << "   " << p.salariu;
    return os;
}

void f()
{  
    for (int i = 0; i < 10; i++)
    {
        static int j = 0; int k = 0;
        cout  << i << "  " << j << "  " << k << endl, j++, k++;
    }            
}
int main()
{
    /*int x(10), & ri=x, *pi;
    pi = &x;
    ri = 20; cout << x<<endl;
    *pi = 30; cout << x << endl;*/
    
    Pers p1;  Pers& rp = p1; 
    Pers p2("Adam Vasile",5500);
    operator<<(cout, p2);
    
    Pers p3 = p2; // default
    cout << "\n copyCon p3: " << p3 << endl;

    cout << "\nDispunem de " << Pers::getNrPers() << " persoane";
    f(); f();

}
