package Cafe;

public class Cafe {
	
	private double money;
	private Game[] gamesInCafe;
	private Game[] rentedOutGames;

	public Cafe(Game[] games, double startingMoney) {
		this.gamesInCafe = games;
		this.money = startingMoney;
		this.rentedOutGames = new Game[0];
	}
	public void rentOutGame(String name) {
		// Cost of renting is the game’s price * 0.5
		//빌려간 게임인지 체크.
		if(this.getIndexRentedOutGames(name) == -1) {
			//게임의 quality 체크.
			if(this.gamesInCafe[this.getIndexGamesInCafe(name)].getQuality() != "Bad") {
				//빌려간 게임을 저장하는 새로운 게임을 만든다.
				Game[] rentGames = new Game[this.rentedOutGames.length + 1];
				for(int i = 0;i < this.rentedOutGames.length;++i) {
					rentGames[i] = this.rentedOutGames[i];
				}
				this.money += this.gamesInCafe[this.getIndexGamesInCafe(name)].getPrice() * 0.5;
				rentGames[this.rentedOutGames.length] = this.gamesInCafe[this.getIndexGamesInCafe(name)];
				//rentedOutGames의 배열 크기를 늘린다.
				this.rentedOutGames = new Game[rentGames.length];
				//깊은 복사를 이용하여 업데이트해 준다.
				for(int i = 0;i < this.rentedOutGames.length;++i) {
					this.rentedOutGames[i] = rentGames[i];
				}
				System.out.println("Game rented succefully");
			}else {
				System.out.println("Not enough quality");
			}
		}else {
			System.out.println("This is not one of our games!");
		}
	}
	public void returnGame(String name) {
		//빌려간 게임인지 체크.
		if(this.getIndexRentedOutGames(name) != -1) {
			this.gamesInCafe[this.getIndexGamesInCafe(name)].lowerQuality();
			//빌려간 게임들을 새롭게 저장한다.
			Game[] rentGames = new Game[this.rentedOutGames.length - 1];
			for(int i = 0, j = 0;i < rentGames.length;++i, ++j) {
				if(j == this.getIndexRentedOutGames(name)) {
					++j;
				}
				rentGames[i] = this.rentedOutGames[j];
			}
			//rentedOutGames 배열 크기 변환.
			this.rentedOutGames = new Game[rentGames.length];
			//깊은 복사
			for(int i = 0;i < this.rentedOutGames.length;++i) {
				this.rentedOutGames[i] = rentGames[i];
			}
			System.out.println("Game returned succefully");
		}else {
			System.out.println("This is not one of our games that is rented out!");
		}
	}
	public void buyGame(Game game) {
		//게임을 사기 위해 금액이 충분한지 체크
		if(game.getPrice() <= this.money) {
			//새롭게 구입한 게임과 기존 게임들을 새로운 배열에 저장.
			Game[] games = new Game[this.gamesInCafe.length + 1];
			for(int i = 0;i < this.gamesInCafe.length;++i) {
				games[i] = this.gamesInCafe[i];
			}
			games[this.gamesInCafe.length] = game;
			//gamesInCafe 배열 크기 변환.
			this.gamesInCafe = new Game[games.length];
			//깊은 복사.
			for(int i = 0;i < this.gamesInCafe.length;++i) {
				this.gamesInCafe[i] = games[i];
			}
			this.money -= game.getPrice();
			System.out.println("Game bought succefully");
		}else {
			System.out.println("Not enough funds for money");
		}
	}
	public void printCafeDetails() {
		// Prints all games in the cafe and rented out, and the money in the register
		//예시에 맞게 print.
		System.out.println("Money: " + this.money);
		System.out.println("Games in cafe:");
		for(int i = 0;i < this.gamesInCafe.length;++i) {
			System.out.println(this.gamesInCafe[i].toString());
		}
		System.out.println("Games rented out:");
		for(int i = 0;i < this.rentedOutGames.length;++i) {
			System.out.println(this.rentedOutGames[i].toString());
		}
	}
	public void repairGame(String name) {
		//가진 게임 속에 있는지 체크.
		if(this.getIndexGamesInCafe(name) != -1) {
			//가진 금액이 게임을 고치기에 충분한지 체크.
			if(this.gamesInCafe[this.getIndexGamesInCafe(name)].getRepairCost() <= this.money) {
				//비용 지불.
				this.money -= this.gamesInCafe[this.getIndexGamesInCafe(name)].getRepairCost();
				this.gamesInCafe[this.getIndexGamesInCafe(name)].repair();	
				System.out.println("Repaired succefully, remaining money: " + this.money);
			}else {
				System.out.println("Not enough funds for money");
			}
		}else {
			System.out.println("This is not one of our games!");
		}
	}
	private int getIndexGamesInCafe(String name) {
		// Helper function to get the index of the given game in the array, -1 if game doesn’t exist.
		//가진 게임에 존재하는지 체크.
		for(int i = 0;i < this.gamesInCafe.length;++i) {
			if(this.gamesInCafe[i].getName().equals(name)) {
				return i;
			}
		}
		return -1;
	}
	private int getIndexRentedOutGames(String name) {
		// Helper function to get the index of the given game in the array, -1 if game doesn’t exist.
		//빌려간 게임에 존재하는지 체크
		for(int i = 0;i < this.rentedOutGames.length;++i) {
			if(this.rentedOutGames[i].getName().equals(name)) {
				return i;
			}
		}
		return -1;
	}
	
	public double getMoney() {
		return this.money;
	}
	
}
