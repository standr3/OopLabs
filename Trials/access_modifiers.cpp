#include <iostream>

using namespace std;


class A {


private:
	int a;
protected:
	int b;
public: 
	int c;

	A() : a(1), b(2), c(3)
	{
		cout << "\nA type object constructor called!\n";
	}

	~A() {
		cout << "\nA type object destructor called!\n";
	}

	// getter must be public
	int getPrivateAttributeA() {
		return this->a;
	}
	int getPrivateAttributeB() {
		return this->b;
	}
};

void testAccess(A& object) {

	//cout << "Private atribute: " << object.a << endl;
	//--> getter
	cout << "Private atribute: " << object.getPrivateAttributeA() << endl;

	//cout << "Protected atribute: " << object.b << endl;
	//--> getter
	cout << "Protected atribute: " << object.getPrivateAttributeB() << endl;

	cout << "Public  atribute: " << object.c << endl;
}

int main() {

	A obj;
	testAccess(obj);

	return 0;
}
