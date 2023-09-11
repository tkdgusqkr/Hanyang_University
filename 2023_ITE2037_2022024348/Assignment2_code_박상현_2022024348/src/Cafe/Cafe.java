package Cafe;

public class Cafe {
	private double money;
	private Game[] gamesInCafe;
	private Game[] rentedOutGames;
	Cafe(Game[] games, double startingMoney){
		this.gamesInCafe = games;
		this.money = startingMoney;
		this.rentedOutGames = new Game[this.gamesInCafe.length];
	}
	public void rentedOutGame(String name) {
		int index = this.getIndexGamesInCafe(name);
		if(index == this.gamesInCafe.length) {
			System.out.println("Not exist");
		}else {
			if(this.gamesInCafe[index].getQuality().equals("Bad")) {
				System.out.println("Bad quality");
			}else {
				for(int i = 0;i < this.rentedOutGames.length;++i) {
					if(this.rentedOutGames[i] == null) {
						this.rentedOutGames[i] = this.gamesInCafe[index];
						this.money += 0.5 * this.gamesInCafe[index].getPrice();
						this.gamesInCafe[index] = null;
						//Sort gamesInCafe
						for(int j = index;j < this.gamesInCafe.length - 1;++j) {
							Game tmp = this.gamesInCafe[j];
							this.gamesInCafe[j] = this.gamesInCafe[j + 1];
							this.gamesInCafe[j + 1] = tmp;
						}
						System.out.println("Game rented successfully");
						break;
					}
				}
			}
		}
	}
	public void returnGame(String name) {
		int index = this.getIndexRentedOutGames(name);
		if(index == this.rentedOutGames.length) {
			System.out.println("Not exist");
		}else {
			for(int i = 0;i < this.gamesInCafe.length;++i) {
				if(this.gamesInCafe[i] == null) {
					this.gamesInCafe[i] = this.rentedOutGames[index];
					this.gamesInCafe[i].lowerQuality();
					this.rentedOutGames[index] = null;
					//Sort rentedOutGames
					for(int j = index;j < this.rentedOutGames.length - 1;++j) {
						Game tmp = this.rentedOutGames[j];
						this.rentedOutGames[j] = this.rentedOutGames[j + 1];
						this.rentedOutGames[j + 1] = tmp;
					}
					System.out.println("Game returned successfully");
					break;
				}
			}
		}
	}
	public void buyGame(Game game) {
		if(this.money < game.getPrice()) {
			System.out.println("Not enough money");
		}else {
			Game[] newGames = new Game[this.gamesInCafe.length + 1];
			int i;
			for(i = 0;i < this.gamesInCafe.length && this.gamesInCafe[i] != null;++i) {
				newGames[i] = this.gamesInCafe[i];
			}
			newGames[i] = game;
			this.gamesInCafe = newGames;
			Game[] newRentedGames = new Game[this.rentedOutGames.length + 1];
			for(i = 0;i < this.rentedOutGames.length && this.rentedOutGames[i] != null;++i) {
				newRentedGames[i] = this.rentedOutGames[i];
			}
			this.rentedOutGames = newRentedGames;
			this.money -= game.getPrice();
			System.out.println("Game bought successfully");
		}
	}
	public void printCafeDetails() {
		System.out.println("Money: " + this.money);
		System.out.println("Games in cafe:");
		for(int i = 0;i < this.gamesInCafe.length && this.gamesInCafe[i] != null;++i) {
			System.out.print(this.gamesInCafe[i]);
			if(this.gamesInCafe[i] instanceof BoardGame) {
				System.out.println(", type: Board");
			}else if(this.gamesInCafe[i] instanceof CardGame) {
				System.out.println(", type: Card");
			}else if(this.gamesInCafe[i] instanceof ElectronicGame) {
				System.out.println(", type: Electronic");
			}
		}
		System.out.println("Games rented out:");
		for(int i = 0;i < this.rentedOutGames.length && this.rentedOutGames[i] != null;++i) {
			System.out.print(this.rentedOutGames[i]);
			if(this.rentedOutGames[i] instanceof BoardGame) {
				System.out.println(", type: Board");
			}else if(this.rentedOutGames[i] instanceof CardGame) {
				System.out.println(", type: Card");
			}else if(this.rentedOutGames[i] instanceof ElectronicGame) {
				System.out.println(", type: Electronic");
			}
		}
	}
	public void repairGame(String name) {
		int index = this.getIndexGamesInCafe(name);
		if(index == this.gamesInCafe.length) {
			System.out.println("Not exist");
		}else {
			if(this.money < this.gamesInCafe[index].getRepairCost()) {
				System.out.println("Not enough money");
			}else {
				this.money -= this.gamesInCafe[index].getRepairCost();
				this.gamesInCafe[index].repair();
				System.out.println("Repaired successfully, remaining money: " + this.money);
			}
		}
	}
	public int getIndexGamesInCafe(String name) {
		int i;
		for(i = 0;i < this.gamesInCafe.length;++i) {
			if(this.gamesInCafe[i].getName().equals(name)) {
				break;
			}
		}
		return i;
	}
	public int getIndexRentedOutGames(String name) {
		int i;
		for(i = 0;i < this.rentedOutGames.length;++i) {
			if(this.rentedOutGames[i].getName().equals(name)) {
				break;
			}
		}
		return i;
	}
	public Game[] getGame() {
		return this.gamesInCafe;
	}
}
