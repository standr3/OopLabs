# lab1  
switch parametri prin valoare/pointeri/referinte;  
# lab2  
cerinta1: medie array + inlocuire cu val_max pentru o conditie;  
cerinta2: adaugare valoare dupa mai multe elemente din array care indeplinesc o conditie;  
cerinta3: eliminare primele k valori dintr-un array;  
# lab3
char* | float* | char[] :   
> friend ostream& operator<< (ostream& os, Produs& p)  
> void setDenumire(const char* _denumire)   
> char* getDenumire()  
# lab4  
string | int * : 
membru static
init global static 
# lab5
CustomException  
enum type
> Student& operator=(const Student& s)
> int getNota(int i) -> throws exception  
> void setNume(string _nume) -> throws ptr to CustomException  
# lab6
const int :
lista_init  
> Student& operator=(const Student& s) {..delete[]..return *this; }  
> Student operator+(float sold) { ..  rez = *this .. return rez; }  
> Student& operator+=(float sold) { .. return *this; }  
> pre : Student& operator++() { .. return *this; }   
> post : Student operator++(int) { .. copie = *this; .. return copie; }  
> int& operator[](int index)   
> operator string()  
> operator string()  
> friend Student operator+(float sold, Student s)
# lab7
> bool operator> (const Student& s)  
> Student operator!() { .. rez = *this; .. delete[] .. return rez; }  
> float operator()(int index1, int index2)  
> float operator()()  
> Student operator++(int)  
> Student operator-(int x)  
> friend ostream& operator<<(ostream& out, const Student& s);  
> friend istream& operator>>(istream& in, Student& s);  
# lab8
> ostream& operator<<(ostream& out, Anotimp a)  
> istream& operator>>(istream& in, Anotimp& a)  
