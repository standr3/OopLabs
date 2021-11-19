#include <iostream>

using namespace std;

class Pers
{
    private:
        int marca=100;
    public:
        char nume[50]="Noname";
        Pers()
        {
            strcpy_s(nume, "Popescu");
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
    Pers p1; p1.display();

}


// Debug program: F5 or Debug > Start Debugging menu
