#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pers
{
private:
    int marca = 100;
    friend ostream& operator<<(ostream& os, Pers& p)
    {
        os << p.marca << " - " << p.pnume << "   " << p.salariu;
        return os;
    }
    static int nrPers;
public:
    char* pnume = nullptr;
    
    Pers(const char* _nume = "Popescu Ion", double _salariu = 2550.)
        : marca(++nrPers), salariu(_salariu)
    {
        pnume = new char[strlen(_nume) + 1];
        strcpy(pnume, _nume);
    }
    Pers(const Pers& src): marca(++nrPers), salariu(src.salariu)
    {
        pnume = new char[strlen(src.pnume) + 1];
        strcpy(pnume, src.pnume);
        cout << "\nCopy cons";
    }
    Pers& operator=(Pers & src)
    {
        if (this != &src)
        {
            if (pnume != nullptr) delete[] pnume;
            pnume = new char[strlen(src.pnume) + 1];
            strcpy(pnume, src.pnume);
            marca = src.marca; salariu = src.salariu;
        }
        else cerr << "\nEroare auto-asignare";
        return *this;
    }

    ~Pers()
    {
        nrPers--;
        if(pnume!=nullptr) delete[] pnume;
    }
protected:
    double salariu = 2350;
};
    
Pers f(Pers p)// copy cons => call by value
{
    /* */
    return p;// copy cons => return by value
}
int Pers::nrPers = 0;


int main()
{
 
    Pers p1("Adam Vasile", 5500);
    Pers p2(p1), p3=p1, // 2x copy cons => init
        p4("Patru Valeria", 5000);
    p1.pnume[0] = 'X'; // *(p1.pnume+5)='x';
    cout << endl<<p2 << endl<<p1<<endl;
   // char text[50]; char* pt = text;
    f(p2);// 2x copy cons => call & return
    p3 = p4; cout <<endl<< p3<<endl;

}
