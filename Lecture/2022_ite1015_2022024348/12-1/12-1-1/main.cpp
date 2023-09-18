#include <iostream>
using namespace std;
template <typename T>
void myswap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a1, b1;
	cin >> a1 >> b1;
	myswap(a1, b1);
	cout << "After calling myswap(): " << a1 << ' ' << b1 << endl;
	double a2, b2;
	cin >> a2 >> b2;
	myswap(a2, b2);
	cout << "After calling myswap(): " << a2 << ' ' << b2 << endl;
	string a3, b3;
	cin >> a3 >> b3;
	myswap(a3, b3);
	cout << "After calling myswap(): " << a3 << ' ' << b3 << endl;
	return 0;
}
