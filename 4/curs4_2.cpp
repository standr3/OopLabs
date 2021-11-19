#include <iostream>
#include <string>
using namespace std;

class Pers
{
private:
    const int marca;
public:
    string nume;
protected:
    int nrJoburi = 0;
    double* venituri = nullptr;
    double salariu;
    static int nrPers;

public:
    Pers(string  n = "NoName", double s = 1950.) : marca(++nrPers), nume(n)
    {
        salariu = s;
    }  

    Pers( string  n, double s , int nrJ, double *pv) 
        : marca(++nrPers), nume(n), salariu ( s)
    {
        nrJoburi = nrJ; venituri = nullptr;
        if (nrJoburi > 0)
        {
            venituri = new double[nrJoburi];
            for (int i = 0; i < nrJoburi; i++)
                venituri[i] = pv[i];
        }
    }

    Pers(const Pers& src) : marca(++nrPers)
    {
        nume = src.nume; salariu = src.salariu;
        nrJoburi = src.nrJoburi; venituri = nullptr;
        if (src.nrJoburi > 0)
        {
            venituri = new double[nrJoburi];
            for (int i = 0; i < nrJoburi; i++)
                venituri[i] = src.venituri[i];
        }
    }
    void addJob(double v)
    {
        double* aux = venituri;
        nrJoburi++;
        venituri = new double[nrJoburi];
        for (int i = 0; i < nrJoburi-1; i++)
            venituri[i] = aux[i];
        venituri[nrJoburi - 1] = v;
        if (aux != nullptr) delete []aux;
    }
    void removeJob(int poz) {  }

    ~Pers()
    {
        // nrPers--;
        // cout << "\n Destructor " << nume;
        if (venituri != nullptr) delete [] venituri;        
    }

    Pers& operator= (const Pers & src) // p1=p2=p3;
    {
        // marca??
        if (this != &src) // test auto-assignare
        {
            nume = src.nume; salariu = src.salariu;  
            nrJoburi = src.nrJoburi; 
            if (venituri != nullptr) delete[]venituri; 
            if (nrJoburi > 0)
            {
                venituri = new double[nrJoburi];
                for (int i = 0; i < nrJoburi; i++)
                    venituri[i] = src.venituri[i];
            }
        }
        return *this;
    }

private:
    friend ostream& operator<< (ostream& os, Pers& p)
    {
        os << p.marca << "\t" << p.nume << "\t\t" << p.salariu << " lei";
        os << "\n\t\t\tVenituri: ";
        for (int i = 0; i < p.nrJoburi; i++) os << p.venituri[i] << "   ";
        return os;
    }

};

int Pers::nrPers = 0;

void fv(Pers p) { cout << "\n Apel prin valoare"; }

int main()
{
    Pers p1("Popa", 2000.), p2, vp[10] = { Pers("DouaSute", 200000.),Pers("TreiSute", 300000.) };
    
    Pers p4(p1), p5 = p2;
    cout << "\n p4 :  " << p4;
    
    double pv[] = { 6500., 6600., 6800., 6900. };
    Pers p6("Sasu Vasile", 6500., sizeof(pv) / sizeof(pv[0]), pv );
    cout << "\n p6 :  " << p6;
    p6.addJob(7000.); cout << "\n p6 add :  " << p6;
    p1.addJob(10000.); p1.addJob(20000.); cout << "\n p1 add :  " << p1;

    Pers p10(p6); cout << "\n p10 :  " << p10;
    fv(p10);

    p1 = p10; cout << "\n p1 dupa op= :  " << p1;


}
