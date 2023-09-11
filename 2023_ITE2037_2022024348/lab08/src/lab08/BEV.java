package lab08;

import java.time.*;

public class BEV extends Car{
	
	private static int carNum;
	private static int CO2emission;
	private int GHGPERCAR = 25;
	
	public BEV() {
		super();
	}
	public BEV(String name, LocalDate date, int carNum) {
		this.name = name;
		this.date = date;
		this.carNum += carNum;
		this.CO2emission += carNum * this.GHGPERCAR;
	}

	public boolean equals(BEV bev) {
		if(bev.name.equals(this.name) && bev.date.equals(this.date)) {
			return true;
		}else {
			return false;
		}
	}
	public String toString() {
		return "name: " + this.name + ", date: " + this.date + ", carNum: " + this.carNum;
	}
	
	int totalCO2() {
		System.out.println("BEV emit CO2 most when generating electric energy" );
		return this.CO2emission;
	}
	
}
