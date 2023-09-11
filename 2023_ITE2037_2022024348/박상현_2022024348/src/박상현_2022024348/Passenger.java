package 박상현_2022024348;

public class Passenger {
	private String name;
	private double weight;
	private int age;
	public Passenger(String name, double weight, int age) {
		this.name = name;
		this.weight = weight;
		this.age = age;
	}
	public String toString() {
		return "Name:" + this.name + ",weight:" + this.weight + "KG,age:" + this.age + ".";
	}
}
