# [lab1](https://github.com/standr3/OopLabs/blob/main/1/laborator01.cpp)  
switch parametri prin valoare/pointeri/referinte;  
# [lab2](https://github.com/standr3/OopLabs/blob/main/2/lab2.cpp)  
cerinta1: medie array + inlocuire cu val_max pentru o conditie;  
cerinta2: adaugare valoare dupa mai multe elemente din array care indeplinesc o conditie;  
cerinta3: eliminare primele k valori dintr-un array;  
# [lab3](https://github.com/standr3/OopLabs/blob/main/3/lab3.cpp)
char* | float* | char[] :   
> friend ostream& operator<< (ostream& os, Produs& p)  
> void setDenumire(const char* _denumire)   
> char* getDenumire()  
# [lab4](https://github.com/standr3/OopLabs/blob/main/4/lab4.cpp)  
string | int * : 
membru static
init global static 
# [lab5](https://github.com/standr3/OopLabs/blob/main/5/lab5.cpp)
CustomException  
enum type
> Student& operator=(const Student& s)
> int getNota(int i) -> throws exception  
> void setNume(string _nume) -> throws ptr to CustomException  
# [lab6](https://github.com/standr3/OopLabs/blob/main/6/lab6.cpp)
const int :
lista_init  
> [Student& operator=(const Student& s) {..delete[]..return *this; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L57)  
> [Student operator+(float sold) { ..  rez = *this .. return rez; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L76)  
> [Student& operator+=(float sold) { .. return *this; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L83)  
> pre : [Student& operator++() { .. return *this; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L89)   
> post : [Student operator++(int) { .. copie = *this; .. return copie; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L95)  
> [int& operator[](int index)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L101)   
> [operator string()](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L108)  
> [explicit operator float()](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L110)  
> [friend Student operator+(float sold, Student s)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/6/lab6.cpp#L129)
# [lab7](https://github.com/standr3/OopLabs/blob/main/7/lab07.cpp)
> [bool operator> (const Student& s)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L78)  
> [Student operator!() { .. rez = *this; .. delete[] .. return rez; }](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L85)  
> [float operator()(int index1, int index2)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L94)  
> [float operator()()](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L103)  
> [Student operator++(int)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L108)  
> [Student operator-(int x)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L121)  
> [friend ostream& operator<<(ostream& out, const Student& s);]()  
> [friend istream& operator>>(istream& in, Student& s);]()  
# [lab8](https://github.com/standr3/OopLabs/blob/main/8/lab8.cpp)
> [ostream& operator<<(ostream& out, Anotimp a)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L177)  
> [istream& operator>>(istream& in, Anotimp& a)](https://github.com/standr3/OopLabs/blob/336717bf81239e4c9c7a3fd25d8aafcfdc6e69c5/7/lab07.cpp#L153)  
