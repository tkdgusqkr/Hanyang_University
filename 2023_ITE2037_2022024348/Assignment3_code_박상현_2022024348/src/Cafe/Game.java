package Cafe;

abstract class Game {
	private String name;
	private double price;
	protected int quality;//0-100
	Game(String name, double price, int quality){
		this.name = name;
		this.price = price;
		this.quality = quality;
	}
	//Returns game's name, quality and price
	public String toString() {
		return "Name: " + this.name + ", Quality: " + this.getQuality() + ", Price: " + this.price;
	}
	public void repair() {
		this.quality = 100;
	}
	//Return name
	public String getName() {
		return this.name;
	}
	//Return price
	public double getPrice() {
		return this.price;
	}
	public abstract double getRepairCost();
	public abstract void lowerQuality();
	public abstract String getQuality();
}
