package 박상현_2022024348;
import java.util.Scanner;
public class AirBalloon {
	private double weightCapacity;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Passenger[] p = new Passenger[3];
		for(int i = 0;true;) {
			Scanner scan = new Scanner(System.in);
			System.out.println("What is the name of the passenger?");
			String name = scan.next();
			System.out.println("What is the weight of the passenger?");
			double weight = scan.nextDouble();
			if(weight <= 200) {
				System.out.println("What is the age of the passenger?");
				int age = scan.nextInt();
				p[i] = new Passenger(name, weight, age);
				System.out.println(p[i].toString());
				++i;
			}else {
				System.out.println("The weight exceeds the limit, Weight is " + weight +" of maximum 200");
			}
			scan.close();
		}
	}

}
