package 박상현_2022024348;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bank bank = new Bank();
		SavingsAccount sa = new SavingsAccount(0, 1.03);
		CheckingsAccount ca = new CheckingsAccount(0, 50);
		bank.addAccount(sa);
		bank.addAccount(ca);
		bank.printAccountInformation();
		bank.deposit(0, 500);
		bank.deposit(1, 100);
		bank.withdraw(1, 175);
		bank.withdraw(1, 150);
		bank.printAccountInformation();
	}

}
