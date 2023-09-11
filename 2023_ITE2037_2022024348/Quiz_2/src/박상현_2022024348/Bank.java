package 박상현_2022024348;

public class Bank {
	public Account[] accounts;
	Bank(){
		this.accounts = new Account[0];
	}
	public int addAccount(Account account) {
		Account[] newAccounts = new Account[this.accounts.length + 1];
		int i;
		for(i = 0;i < this.accounts.length;++i) {
			newAccounts[i] = this.accounts[i];
		}
		newAccounts[i] = account;
		accounts = newAccounts;
		return i;
	}
	public void deposit(int index, double amount) {
		this.accounts[index].deposit(amount);
	}
	public void withdraw(int index, double amount) {
		this.accounts[index].withdraw(amount);
	}
	public void printAccountInformation() {
		for(int i = 0;i < this.accounts.length;++i) {
			System.out.println(this.accounts[i]);
		}
	}
}
