#include <iostream>
#include "accounts.h"
using namespace std;
void AccountManager::Deposit(int account_ID,int deposit_amount)
{
	if(accounts[account_ID].balance+deposit_amount>1000000)
	{
		cout<<"Failure: Deposit from user "<<account_ID<<' '<<deposit_amount;
	}
	else
	{
		accounts[account_ID].balance+=deposit_amount;
		cout<<"Success: Deposit to user "<<account_ID<<' '<<deposit_amount;
	}
	cout<<"\nBalance of user "<<account_ID<<": "<<accounts[account_ID].balance<<'\n';

}
void AccountManager::Withdraw(int account_ID,int withdraw_amount)
{
	if(accounts[account_ID].balance<withdraw_amount)
	{
		cout<<"Failure: Withdraw from user "<<account_ID<<' '<<withdraw_amount;
	}
	else
	{
		accounts[account_ID].balance-=withdraw_amount;
		cout<<"Success: Withdraw to user "<<account_ID<<' '<<withdraw_amount;
	}
	cout<<"\nBalance of user "<<account_ID<<": "<<accounts[account_ID].balance<<'\n';
}
void AccountManager::Transfer(int from_account_ID,int to_account_ID,int amount)
{
	if(accounts[from_account_ID].balance<amount)
	{
		cout<<"Failure: Transfer from user "<<from_account_ID<<" to user "<<to_account_ID<<' '<<amount;
	}
	else
	{
		if(accounts[to_account_ID].balance+amount>1000000)
		{
			cout<<"Failure: Transfer from user "<<from_account_ID<<" to user "<<to_account_ID<<' '<<amount;
		}
		else
		{
			accounts[from_account_ID].balance-=amount;
			accounts[to_account_ID].balance+=amount;
		}
	}
	cout<<"\nBalance of user "<<from_account_ID<<": "<<accounts[from_account_ID].balance<<"\nBalance of user "<<to_account_ID<<": "<<accounts[to_account_ID].balance<<'\n';
}
