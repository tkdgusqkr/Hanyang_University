#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"
using namespace std;
int main()
{
	while(1)
	{
		set<int> set0,set1;
		string s,op;
		int cnt=0;
		cin>>s;
		if(s=="0")
		{
			break;
		}
		else
		{
			string str="";
			while(1)
			{
				string S;
				cin>>S;
				if(S=="}")
				{
					if(cnt)
					{
						set1=parseSet(str);
						break;
					}
					else
					{
						set0=parseSet(str);
					}
				}
				else if(S=="{")
				{
					cnt=1;
					str="";
				}
				else if(S=="+")
				{
					op="+";
				}
				else if(S=="*")
				{
					op="*";
				}
				else if(S=="-")
				{
					op="-";
				}
				else
				{
					str+=S;
					str.push_back(' ');
				}
			}
		}
		if(op=="+")
		{
			set<int> set=getUnion(set0,set1);
			printSet(set);
		}
		else if(op=="*")
		{
			set<int> set=getIntersection(set0,set1);
			printSet(set);
		}
		else if(op=="-")
		{
			set<int> set=getDifference(set0,set1);
			printSet(set);
		}
	}
}
