package manager;

import account.*;
import java.util.Random;
import java.time.*;

public class AccountManager {

	public static void main(String[] args) {
		
		int month = 0;
		
		Random rnd = new Random();
		
		LocalDate created = LocalDate.of(2021, 12, 01);
		
		Account park = new Account("Park", 5, created);
		
		System.out.println(park.toString());
		
		while(park.getBalance() < 10000) {
			if(month >= 12) {
				if(created.getMonthValue() == 1) {
					int win = rnd.nextInt(10);
					if(win == 0) {
						park.receiveIncome(100);
						System.out.println("이벤트 당첨!");
					}
				}
			}
			
			park.receiveIncome(100);
			park.receiveInterest();
			
			if(month == 36) {
				park.increaseYearlyInterest(2);
				System.out.println("가입 후 3년이 지나서 이자율이 2% 인상되었습니다.");
			}
			
			month += 1;
			created = created.plusMonths(1);
		}
		
		System.out.println(park.toString() + ", 1억 모으기 끝: " + created);
	}

}
