#include <iostream>

using namespace std;

class A
{
};
class B : public A
{
};
class C : public B
{
};
  
int main(){
	int n;
	cout << "input num(0~2):";
	cin >> n;	
	
	try{
		if(n == 0)
			throw A();
		else if(n == 1)	
			throw B();
		else if (n ==2)
			throw C();
		else
			throw string("invalid input");
	}
	//implement here
	catch(C& msg){
		cout << "throw C has been called" << endl;
	}catch(B& msg){
		cout << "throw B has been called" << endl;
	}catch(A& msg){
		cout << "throw A has been called" << endl;
	}catch(string& msg){
		cout << msg <<endl;
	}

	return 0;
}
