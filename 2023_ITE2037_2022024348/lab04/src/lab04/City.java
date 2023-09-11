package lab04;

import java.util.Random;

public class City {

	private String name;
	private int locationX;
	private int locationY;
	
	Random rnd = new Random();
	
	public City(String name, int locationX, int locationY) {
		this.name = name;
		this.locationX = locationX;
		this.locationY = locationY;
	}
	public City(String name) {
		this.name = name;
		this.locationX = rnd.nextInt(361);
		this.locationY = rnd.nextInt(361);
	}
	
	public String getName() {
		return this.name;
	}
	public int getX() {
		return this.locationX;
	}
	public int getY() {
		return this.locationY;
	}
	public boolean sameCity(City city) {
		if(this.equals(city)) {
			return true;
		}else {
			return false;
		}
	}
	public String toString() {
		return this.getName() + ", " + Integer.toString(this.getX()) + ", " + Integer.toString(this.getY());
	}
	
	public static double distance(City city1, City city2) {
		return Math.sqrt(Math.pow((double)(city1.locationX - city2.locationX), 2) + Math.pow((double)(city1.locationY - city2.locationY), 2));
	}

}
