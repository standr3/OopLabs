#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Stud
{
    int matricol;
    string nume;
public:
    Stud(int m = 10, string n = "Popa Ioan")
        : matricol(m), nume(n)
    {

    }
    friend ostream& operator<<(ostream& ost, Stud& s)
    {
        ost << s.matricol << "\t" << s.nume;
        return ost;
    }
    friend istream& operator>>(istream& ist, Stud& s)
    {
        cout << "\nMatricol: ";  ist >> s.matricol;
        cout << "\nNume: "; ist.ignore(50, '\n'); 
        getline(ist, s.nume);
        return ist;
    }
    friend ofstream& operator<<(ofstream& ost, Stud& s)
    {
        ost << s.matricol << endl << s.nume<<endl;
        return ost;
    }
    friend ifstream& operator>>(ifstream& ist, Stud& s)
    {
        ist >> s.matricol;
        ist.ignore(50, '\n');
        getline(ist, s.nume);
        return ist;
    }

};

int main()
{
    Stud s1(123, "Adam Ana-Maria"), s2, s3, s4;
   // cin >> s2;
    cout << endl << s1 << endl << s2;
    
    ofstream fisOut("stud.dat");
    if (!fisOut) 
     { cerr << "\nFisier5 in scriere nedeschis"; }
    fisOut << s1 << s2; fisOut.close();

    ifstream fisIn("stud.dat");
    if (!fisIn)
    {
        cerr << "\nFisier  in citire nedeschis";
    }
    fisIn >> s3 >> s4; fisIn.close();
    cout << endl << s3 << endl << s4;

    int* pi;
    pi = new int(10);
    cout << "\n sizeof(pi): " << sizeof(pi) << "\t sizeof(*pi): " << sizeof(*pi);
    string nume = "Cineva ceva ";
  //  nume.size(), nume.resize(), nume.length(), sizeof(nume)

}
