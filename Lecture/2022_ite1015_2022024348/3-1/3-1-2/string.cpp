#include <iostream>
using namespace std;
int main()
{
	string str1,str2,cstr;
	cin>>str1>>str2;
	cstr=str1+str2;
	cout<<cstr<<endl<<cstr[0]<<endl<<cstr[cstr.length()-1]<<endl;
}
