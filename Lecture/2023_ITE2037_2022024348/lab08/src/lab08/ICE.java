package lab08;

import java.time.*;

public class ICE extends Car {
	
	private static int carNum;
	private static int CO2emission;
	private int GHGPERCAR = 35;
	
	public ICE() {
		super();
	}
	public ICE(String name, LocalDate date, int carNum) {
		this.name = name;
		this.date = date;
		this.carNum += carNum;
		this.CO2emission += carNum * this.GHGPERCAR;
	}
	
	public boolean equals(ICE ice) {
		if(ice.name.equals(this.name) && ice.date.equals(this.date)) {
			return true;
		}else {
			return false;
		}
	}
	public String toString() {
		return "name: " + this.name + ", date: " + this.date + ", carNum: " + this.carNum;
	}
	
	int totalCO2() {
		System.out.println("ICE emit CO2 most when driving");
		return this.CO2emission;
	}
	
}
