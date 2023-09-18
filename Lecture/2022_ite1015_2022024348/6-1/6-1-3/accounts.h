#ifndef __ACCOUNTS_H__
#define __ACCOUNTS_H__
class Account
{
	public:
		int ID,balance;
};
class AccountManager
{
	public:
		Account *accounts=new Account[10];
		int number=0;
		void Deposit(int account_ID,int deposit_amount);
		void Withdraw(int account_ID,int withdraw_amount);
		void Transfer(int from_account_ID,int to_account_ID,int amount);
};
#endif
