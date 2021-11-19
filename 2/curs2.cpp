#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Pers
{
private:
    const int marca = 100;
public:
    char nume[50] = "Noname";
    /*Pers()
    {
        strcpy(nume, "Popescu");
    }*/
    /*Pers(int m, const char* n, double s)
    {
       marca = m; strcpy(nume, n); salariu = s;
    }*/
    /*Pers(int m =1000, const char* n="Anonim", double s=2550)
    {
        marca = m; strcpy(nume, n); salariu = s;
    }*/
    Pers(int m = 1000, const char* n = "Anonim", double s = 2550)
        : marca(m), salariu(s)
    {
        strcpy(nume, n); 
    }

    ~Pers()
    {
        cerr << "\n\tDestructor pentru " << nume;
    }

    double getSalariu()
    {
        return salariu;
    }
    void setNume(const char *pn)
    {
        if (strlen(pn) < 49)
            strcpy(nume, pn);
        else cerr << "\nNumele depaseste max 50 caractere ";
    }
    void display()
    {
        cout << "\n" << this->marca << " : " << nume << " are " << salariu << " lei";
    }
protected:
    double salariu = 2350;
};


int main()
{
    int x(10);
    Pers p1; p1.display(); 
    char nn1[] = "Adamescu Ion", nn2[] ="Polcovnicu Daniela";
    
    Pers p2( 1000, nn2); 
    {
        Pers p3(300, "Temporar in bloc", 3000);
    }
    p2.display(); 
    cout << "\nSalariul lui " << p2.nume << " este " << p2.getSalariu();
    Pers* pp = new Pers(120, "Popa P", 3900);
    pp->display(); delete pp;
    pp = new Pers(130, "Patrulescu V", 4900); 
    (*pp).setNume("Patrascu V"); cout << "\nNume nou: " << pp->nume;
    delete pp;
}
