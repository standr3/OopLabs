#include<iostream>
using namespace std; 

void cerinta1(int* v, int n) {
	float medie = 0;
	int max = INT_MIN;//v[0]
	for (int i = 0; i < n; i++) {
		medie = medie + v[i];
		if (v[i] > max)
			max = v[i];
	}
	medie = medie / n;

	for (int i = 0; i < n; i++) {
		if (v[i] < medie)
			v[i] = max;
	}
}

void cerinta2(int* &v, int &n, int k)
{
	int* x, m = 0, nr = 0;
	//cate elem are noul vector
	for (int i = 0; i < n; i++)
	{
		if (v[i] > k)
			nr++;//numara cate valori noi adaug in vector
	}
	//alocare zona de memorie vector nou
	x = (int*)malloc((n + nr) * sizeof(int));
	
	//copiere in vector nou din vector vechi
	for (int i = 0; i < n; i++)
	{
		x[m++] = v[i];
		if (v[i] > k)
			x[m++] = 0;
	}
	//dezalocare vector vechi
	free(v);
	//vector vechi pointeaza spre vector nou
	v = x;
	n = n + nr;
}

void cerinta3(int*& v, int& n, int k)
{
	int* x, m = 0;
	x = (int*)malloc((n - k) * sizeof(int));
	for (int i = k; i < n; i++)
		x[m++] = v[i];
	free(v);
	v = x;
	n = n - k;
}

int main()
{
	//1.lucru cu vectori alocati dinamic ( stergere + adaugare)
	int* v;
	int n;
	cin >> n;
	v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "Afisare vector initial: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	//c1. sa se implementeze functia care primeste un vector si dim sa si inlocuieste fiecare val aflata sub medie cu valoarea 
	//maxima din vector.
	//ex: v: 5 6 7 5 6 7 n=6 => v: 7 6 7 7 6 7 n=6.
	cerinta1(v, n);
	cout << "Afisare vector cerinta 1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	//c2. sa se implementeze functia care primeste un vector si dim sa si adauga dupa fiecare valoare mai mare ca un param k
	// valoarea 0.
	//ex: v: 1 5 3 7 n=4 k=4 => v: 1 5 0 3 7 0 n=6
	cerinta2(v, n, 3);
	cout << "Afisare vector cerinta 2: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	//c3. sa se implementeze functia care primeste un vector si dim sa si elimina primele k valori din vector.
	//ex: v: 1 2 3 4 5 6 7 8 n=8 k=3 => v: 4 5 6 7 8 n=5
	cerinta3(v, n, 2);
	cout << "Afisare vector cerinta 3: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	free(v);
	//2.alocare si dezalocare folosind new si delete
	int* p1;
	p1 = new int[10];//aloc zona de memorie pentru 10 int-uri
	delete[] p1;

	int* p2;
	p2 = new int;//aloc zona memorie pentru 1 int
	*p2 = 6;
	delete p2;

	int* p3;
	p3 = new int(10);//apel constructor int-ului
	//p3 = new int;
	// *p3=10;
	delete p3;
	//3. variabile constante
	int y = 6;
	const int vc1 = 8;//variabila constanta
	//vc1 = 5;

	int const vc2 = 6;
	//vc2 = 9;

	//pointer variabil spre continut constant
	const int* pvc = &n;
	pvc = &y;
	//*pvc = 8;

	//pointer constant spre continut variabil
	int* const pvc2 = &n;
	//pvc2 = &y;
	*pvc2 = 9;

	//pointer constant spre continut constant
	const int* const pvc3 = &n;
	//pvc3 = &y;
	//*pvc3 = 10;

	return 0;
}
