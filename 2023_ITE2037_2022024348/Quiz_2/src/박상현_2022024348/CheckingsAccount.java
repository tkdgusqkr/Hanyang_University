package 박상현_2022024348;

public class CheckingsAccount implements Account {
	private double balance;
	private double overdraftLimit;
	public CheckingsAccount(double balance, double overdraftLimit) {
		this.balance = balance;
		this.overdraftLimit = overdraftLimit;
	}
	public String toString() {
		return "Balance:" + this.balance + "OverdraftLimit:" + this.overdraftLimit;
	}
	@Override
	public void deposit(double amount) {
		// TODO Auto-generated method stub
		this.balance += amount;
	}
	@Override
	public void withdraw(double amount) {
		// TODO Auto-generated method stub
		if(this.balance < amount) {
			amount -= this.balance;
			this.balance = 0;
			if(this.overdraftLimit >= amount) {
				this.overdraftLimit -= amount;
			}else {
				System.out.println("This does not work");
			}
		}else {
			this.balance -= amount;
		}
	}
	@Override
	public double getBalance() {
		// TODO Auto-generated method stub
		return this.balance;
	}
}
