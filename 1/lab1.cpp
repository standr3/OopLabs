#include<iostream>
using namespace std;

//transfer prin valoare
void inter1(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

//transfer prin referinta
void inter2(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

//transfer prin pointeri
void inter3(int *a, int *b)
{
	int *t;
	t = a;
	a = b;
	b = t;
}

//transfer prin pointeri
void inter4(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int x, y;
	//cin >> x >> y;
	x = 10; y = 20;
	char s[15] = "testare";
	cout << "x= " << x << " y= " << y << endl;
	inter1(x, y);
	cout << "x= " << x << " y= " << y << endl;

	x = 10; y = 20;
	inter2(x, y);
	cout << "x= " << x << " y= " << y << endl;
	
	x = 10; y = 20;
	inter3(&x, &y);
	cout << "x= " << x << " y= " << y << endl;

	x = 10; y = 20;
	inter4(&x, &y);
	cout << "x= " << x << " y= " << y << endl;
	//cin >> x;
	return 0;
}
