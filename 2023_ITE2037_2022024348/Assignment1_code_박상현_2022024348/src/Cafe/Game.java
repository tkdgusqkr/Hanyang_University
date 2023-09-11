package Cafe;

public class Game {

	private String name;
	private String quality;		// Bad/Okay/Good
	private double price;

	public Game(String name, double price){
		// Quality always starts at “Good”.
		this.name = name;
		this.quality = "Good";
		this.price = price;
	}
	public Game(Game game) {
		this.name = game.name;
		this.quality = game.quality;
		this.price = game.price;
	}
	public String toString() {
		// returns game’s name, quality and price
		return "Name: " + name + ", Quality: " + quality + ", Price: " + price;
	}
	public double getRepairCost() {
		// bad = 0.5 * price , okay = 0.2 * price
		if(this.quality == "Bad") {
			return 0.5 * this.price;
		}else if(this.quality == "Okay") {
			return 0.2 * this.price;
		}else {
			return 0;
		}
	}
	public void repair() {
		//Game의 quality를 한단계씩 증가.
		if(this.quality == "Bad") {
			this.quality = "Okay";
		}else {
			this.quality = "Good";
		}
	}
	public void lowerQuality() {
		// Lowers the quality of the game by 1 tier.
		if(this.quality == "Good") {
			this.quality = "Okay";
		}else {
			this.quality = "Bad";
		}
	}
	
	public String getName() {
		//게임의 이름을 반환.
		return this.name;
	}
	public String getQuality() {
		//게임의 퀄리티를 반환.
		return this.quality;
	}
	public double getPrice() {
		//게임의 가격을 반환.
		return this.price;
	}
	
}
