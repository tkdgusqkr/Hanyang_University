package Cafe;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class CoffeeCorner implements Observer {
	private int coffeeIndex; 
	private HashMap<String, Double> coffeetypes;
	private ArrayList<CoffeeMachine> machines;
	
	public CoffeeCorner(int machineAmount) {
		this.coffeeIndex = 1;
		this.coffeetypes = new HashMap<String, Double>();
		this.coffeetypes.put("Capucino", 3.75);
		this.coffeetypes.put("Americano", 2.5);
		this.coffeetypes.put("Latte", 3.25);
		this.machines = new ArrayList<CoffeeMachine>();
		for(int i = 1;i <= machineAmount;++i) {
			this.machines.add(new CoffeeMachine(i, "Machine " + i));
		}
	}
	public void listCoffeeTypes() {
		for(Map.Entry<String, Double> e : this.coffeetypes.entrySet()) {
			System.out.println(e.getKey() + ", Price: " + e.getValue());
		}
	}
	public double makeCoffee(String type) {
		if(this.coffeeIndex % 2 == 1) {
			this.coffeeIndex += 1;
			this.machines.get(0).subscribe(this);
			this.machines.get(0).start();
			this.machines.get(0).unsubscribe(this);
		}else {
			this.coffeeIndex += 1;
			this.machines.get(1).subscribe(this);
			this.machines.get(1).start();
			this.machines.get(1).unsubscribe(this);
			this.update(coffeeIndex - 1, type);
		}
		return this.coffeetypes.get(type);
	}
	@Override
	public void update(int index, String name) {
		// TODO Auto-generated method stub
		int machineAmount = this.machines.size();
		this.machines.removeAll(machines);
		for(int i = 1;i <= machineAmount;++i) {
			this.machines.add(new CoffeeMachine(index + i, "Machine " + i));
		}
	}	
	public int getIndex() {
		return this.coffeeIndex;
	}

	private class CoffeeMachine extends Thread implements Observable{
		private ArrayList<Observer> observers;
		private int index;
		private String machineName;
		
		public CoffeeMachine(int index, String name) {
			this.observers = new ArrayList<Observer>();
			this.index = index;
			this.machineName = name;
		}
		public void run() {
			try {
				for(int i = 20;i < 100;i += 20) {
					Thread.sleep(2000);
					System.out.println("Coffee with number: " + this.index + " is " + i + "% done.");
				}
				Thread.sleep(3000);
				System.out.println("Coffee with number: " + this.index + " is ready for pickup at " + this.machineName);
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		@Override
		public void subscribe(Observer observer) {
			// TODO Auto-generated method stub
			this.observers.add(observer);
			System.out.println("The coffee is being prepared on " + this.machineName);
			System.out.println("your number is: " + this.index);
		}
		@Override
		public void unsubscribe(Observer observer) {
			// TODO Auto-generated method stub
			this.observers.remove(observer);
		} 
	}
}
