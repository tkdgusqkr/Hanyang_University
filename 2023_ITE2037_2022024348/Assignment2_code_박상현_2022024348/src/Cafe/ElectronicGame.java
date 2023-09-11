package Cafe;

public class ElectronicGame extends Game {
	ElectronicGame(String name, double price, int quality) {
		super(name, price, quality);
	}
	//Return the cost of repairing
	public double getRepairCost() {
		return 0.06 * (100 - this.quality);
	}
	//Lower the quality
	public void lowerQuality() {
		this.quality -= 20;
	}
	//Return the quality of double transformed into String
	public  String getQuality() {
		if(this.quality > 80) {
			return "Good";
		}else if(this.quality < 60) {
			return "Bad";
		}else {
			return "Okay";
		}
	}
}
