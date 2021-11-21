#include <iostream>
#include <Windows.h>

using namespace std;

void switch_values(int a, int b)
{
	int t;
	t = a; a = b; b = t;
}
void switch_references(int& a, int& b)
{
	int t;
	t = a; a = b; b = t;
}
void switch_ptr_values(int* a, int* b) // switches actual addresses
{
	int* t;
	t = a; a = b; b = t;
}
void switch_values_ptr(int* a, int* b) // switches values at ptr adresses
{
	int t;
	t = *a; *a = *b; *b = t;
}

void selector();
bool handler(int);

int main()
{
	selector();
	return 0;
}

void selector()
{
	int selection = -1;
	do {
		system("CLS");
		cout << "What do you want to test?\n";
		cout << "1. switch_values(int, int)\n";
		cout << "2. switch_references(int&, int&)\n";
		cout << "3. switch_ptr_values(int*, int*)\n";
		cout << "4. switch_values_ptr(int*, int*)\n";
		cout << endl << ">> ";

		cin >> selection;
		
		system("CLS");
	} while (handler(selection));

}

bool handler(int fSelected)
{
	//system("CLS");
	int x = 1, y = 2;
	cout << "Given x = 1 and y = 2: \n\n";
	switch (fSelected) {
	case 1:
		cout << "> running switch_values(int, int)\n\n";
		switch_values(x, y);
		break;
	case 2:
		cout << "> running switch_references(int&, int&)\n\n";
		switch_references(x, y);
		break;
	case 3:
		cout << "> running switch_ptr_values(int*, int*)\n\n";
		switch_ptr_values(&x, &y);
		break;
	case 4:
		cout << "> running switch_values_ptr(int*, int*)\n\n";
		switch_values_ptr(&x, &y);
		break;
	default:
		cout << "Invalid input of function!\n\n";
		//getchar();
		system("CLS");
		return true;
	}
	cout << "New values are: x = " << x << " y = " << y << endl;
	cout << "\nPress any key to try again.\n";

	int pressed_key = getchar();

	if (pressed_key == 10) 
		pressed_key = getchar();

	if (GetAsyncKeyState(VK_ESCAPE) != 0)
		return false;

	return true;
}
