package lab09;

import java.util.Scanner;

public class Market {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Wallet wallet = new Wallet("my wallet");
		Scanner scan = new Scanner(System.in);
		while(true) {
			try {
				wallet.empty();
				System.out.print("Enter price: ");
				int expense = scan.nextInt();
				if(expense < 0) {
					throw new NegativeException();
				}else if(expense > 100) {
					throw new TooMuchExpenseException(expense);
				}else if(expense > wallet.getBalance()) {
					throw new TooMuchExpenseException();
				}else {
					wallet.increaseIndex();
					wallet.decreaseBalance(expense);
					System.out.println("peace~~");
				}
			} catch (NegativeException negativeE) {
				System.out.println(negativeE);
				System.out.println("\tat " + negativeE.getStackTrace()[0]);
				System.out.println("oh, sorry!");
			} catch (TooMuchExpenseException tooMuchExpenseE) {
				System.out.println(tooMuchExpenseE);
				System.out.println("\tat " + tooMuchExpenseE.getStackTrace()[0]);
				if(tooMuchExpenseE.getMessage().equals("Over the limit!")) {
					System.out.println("you pay " + tooMuchExpenseE.getInputNum());
				}
				System.out.println("oh, my!");
			} catch (Exception e) {
				System.out.println(e);
				System.out.println("\tat " + e.getStackTrace()[0]);
				System.out.println("the end...");
				scan.close();
				return;
			} finally {
				System.out.println(wallet);
				System.out.println("---transaction complete---\n");
			}
		}
	}

}
