package Cafe;

public class BoardGame extends Game {
	BoardGame(String name, double price, int quality) {
		super(name, price, quality);
	}
	//Return the cost of repairing
	public double getRepairCost() {
		return 0.04 * (100 - this.quality);
	}
	//Lower the quality
	public void lowerQuality() {
		this.quality -= 25;
	}
	//Return the quality of double transformed into String
	public String getQuality() {
		if(this.quality > 70) {
			return "Good";
		}else if(this.quality < 50) {
			return "Bad";
		}else {
			return "Okay";
		}
	}
}
