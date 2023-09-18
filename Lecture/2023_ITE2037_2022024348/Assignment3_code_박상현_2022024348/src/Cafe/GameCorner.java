package Cafe;

import java.util.ArrayList;

public class GameCorner {
	private ArrayList<Game> gamesInCafe;
	private ArrayList<Game> rentedOutGames;

	public GameCorner(ArrayList<Game> games) {
		this.gamesInCafe = games;
		this.rentedOutGames = new ArrayList<Game>();
	}
	public double rentOutGame(String name) {
		int index = this.getIndexGamesInCafe(name);
		if(index == this.gamesInCafe.size()) {
			System.out.println("Not exist");
		}else {
			if(this.gamesInCafe.get(index).getQuality().equals("Bad")) {
				System.out.println("Bad quality");
			}else {
				double cost = this.gamesInCafe.get(index).getPrice() * 0.5;
				this.rentedOutGames.add(this.gamesInCafe.get(index));
				this.gamesInCafe.remove(index);
				System.out.println("Game rented successfully");
				return cost;
			}
		}
		return 0;
	}
	public void returnGame(String name) {
		int index = this.getIndexRentedOutGames(name);
		if(index == this.rentedOutGames.size()) {
			System.out.println("Not exist");
		}else {
			this.rentedOutGames.get(index).lowerQuality();
			this.gamesInCafe.add(this.rentedOutGames.get(index));
			this.rentedOutGames.remove(index);
			System.out.println("Game returned successfully");
		}
	}
	public void buyGame(Game game) {
		this.gamesInCafe.add(game);
	}
	public void printCafeDetails() {
		System.out.println("Games in cafe:");
		for(int i = 0;i < this.gamesInCafe.size();++i) {
			System.out.print(this.gamesInCafe.get(i));
			if(this.gamesInCafe.get(i) instanceof BoardGame) {
				System.out.println(", type: Board");
			}else if(this.gamesInCafe.get(i) instanceof CardGame) {
				System.out.println(", type: Card");
			}else if(this.gamesInCafe.get(i) instanceof ElectronicGame) {
				System.out.println(", type: Electronic");
			}
		}
		System.out.println("Games rented out:");
		for(int i = 0;i < this.rentedOutGames.size();++i) {
			System.out.print(this.rentedOutGames.get(i));
			if(this.rentedOutGames.get(i) instanceof BoardGame) {
				System.out.println(", type: Board");
			}else if(this.rentedOutGames.get(i) instanceof CardGame) {
				System.out.println(", type: Card");
			}else if(this.rentedOutGames.get(i) instanceof ElectronicGame) {
				System.out.println(", type: Electronic");
			}
		}
	}
	public double repairGame(String name) {
		int index = this.getIndexGamesInCafe(name);
		if(index == this.gamesInCafe.size()) {
			System.out.println("Not exist");
		}else {
			double cost = this.gamesInCafe.get(index).getRepairCost();
			this.gamesInCafe.get(index).repair();
			System.out.println("Repaired successfully");
		}
		return 0;
	}
	private int getIndexGamesInCafe(String name) {
		int i;
		for(i = 0;i < this.gamesInCafe.size();++i) {
			if(this.gamesInCafe.get(i).getName().equals(name)) {
				break;
			}
		}
		return i;
	}
	private int getIndexRentedOutGames(String name) {
		int i;
		for(i = 0;i < this.rentedOutGames.size();++i) {
			if(this.rentedOutGames.get(i).getName().equals(name)) {
				break;
			}
		}
		return i;
	}
	
	public ArrayList<Game> getGame(){
		return this.gamesInCafe;
	}
}
