package 박상현_2022024348;

public class SavingsAccount implements Account {
	private double balance;
	private double Interest;
	public SavingsAccount(double balance, double interestRate) {
		this.balance = balance;
		this.Interest = interestRate;
	}
	public void applyInterest() {
		this.balance += this.balance * this.Interest;
	}
	public String toString() {
		return "Balance:" + this.balance + "Interest:" + this.Interest;
	}
	@Override
	public void deposit(double amount) {
		// TODO Auto-generated method stub
		this.balance += amount;
	}
	@Override
	public void withdraw(double amount) {
		// TODO Auto-generated method stub
		if(this.balance >= amount) {
			this.balance -= amount;
		}
	}
	@Override
	public double getBalance() {
		// TODO Auto-generated method stub
		return this.balance;
	}
}
