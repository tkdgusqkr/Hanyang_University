#include <iostream>
#include "accounts.h"
using namespace std;
int main()
{
	AccountManager accountmanager;
	while(1)
	{
		cout<<"\n\nJob?\n";
		char J;
		cin>>J;
		if(J=='N')
		{
			if(accountmanager.number>10)
			{
				cout<<"You can no longer create an account\n";
			}
			else
			{
				accountmanager.accounts[accountmanager.number].ID=accountmanager.number;
				accountmanager.accounts[accountmanager.number].balance=0;
				cout<<"Account for user "<<accountmanager.accounts[accountmanager.number].ID<<" registered\n"<<"Balance of user "<<accountmanager.accounts[accountmanager.number].ID<<": "<<accountmanager.accounts[accountmanager.number].balance<<'\n';
				++accountmanager.number;
			}
		}
		else if(J=='D')	
		{
			int account_ID,deposit_amount;
			cin>>account_ID>>deposit_amount;
			if(account_ID<accountmanager.number)
			{
				accountmanager.Deposit(account_ID,deposit_amount);
			}
			else
			{
				cout<<"Account does not exist\n";
			}
		}
		else if(J=='W')
		{
			int account_ID,withdrawal_amount;
			cin>>account_ID>>withdrawal_amount;
			if(account_ID<accountmanager.number)
			{
				accountmanager.Withdraw(account_ID,withdrawal_amount);
			}
			else
			{
				cout<<"Account does not exist\n";
			}
		}
		else if(J=='T')
		{
			int from_account_ID,to_account_ID,amount;
			cin>>from_account_ID>>to_account_ID>>amount;
			if(from_account_ID<accountmanager.number && to_account_ID<accountmanager.number)
			{
				accountmanager.Transfer(from_account_ID,to_account_ID,amount);
			}
			else
			{
				cout<<"Account does not exist\n";
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
