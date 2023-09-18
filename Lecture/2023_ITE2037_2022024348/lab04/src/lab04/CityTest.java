package lab04;

public class CityTest {

	public static void main(String[] args) {
		
		City seoul = new City("Seoul", 23, 45);
		City paris = new City("Paris", 123, 41);
		City racoon = new City("Racoon City");
		City mega = new City("Mega City");
		
		System.out.println(seoul.toString());
		System.out.println(paris.toString());
		System.out.println(racoon.toString());
		System.out.println(mega.toString());
		
		System.out.println("Seoul-Paris : " + City.distance(seoul, paris) + "\nSeoul-Racoon City : " + City.distance(seoul, racoon) + "\nParis-Mega City : " + City.distance(paris, mega));
		
	}

}
