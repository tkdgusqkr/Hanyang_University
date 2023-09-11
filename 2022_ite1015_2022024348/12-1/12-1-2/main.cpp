#include <iostream>
#include "my_container.h"
using namespace std;
int main()
{
	int n;
	cin >> n;
	MyContainer<int> a(n);
	cin >> a;
	cout << a << endl;
	cin >> n;
	MyContainer<double> b(n);
	cin >> b;
	cout << b << endl;
	cin >> n;
	MyContainer<string> c(n);
	cin >> c;
	cout << c << endl;
}
