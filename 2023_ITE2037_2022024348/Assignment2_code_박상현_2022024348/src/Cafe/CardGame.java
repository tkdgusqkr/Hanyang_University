package Cafe;

public class CardGame extends Game {
	CardGame(String name, double price, int quality) {
		super(name, price, quality);
	}
	//Return the cost of repairing
	public double getRepairCost() {
		return 0.02 * (100 - this.quality);
	}
	//Lower the quality
	public void lowerQuality() {
		this.quality -= 30;
	}
	//Return the quality of double transformed into String
	public  String getQuality() {
		if(this.quality > 60) {
			return "Good";
		}else if(this.quality < 25) {
			return "Bad";
		}else {
			return "Okay";
		}
	}
}
