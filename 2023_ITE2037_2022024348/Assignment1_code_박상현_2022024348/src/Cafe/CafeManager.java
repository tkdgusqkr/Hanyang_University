package Cafe;

import java.util.Scanner;

public class CafeManager {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Game[] games = new Game[2];
		games[0] = new Game("Battleship", 4.25);
		games[1] = new Game("Uno", 7.0);
		Cafe cafe = new Cafe(games, 25.0);
		Scanner scan = new Scanner(System.in);
		//돈이 부족할 떄까지 반복.
		while(cafe.getMoney() > 0) {
			cafe.printCafeDetails();
			System.out.println("What would you like to do:");
			System.out.println("1: Rent a game, 2: Return a game, 3: Repair a game, 4: Buy a game");
			int cmd;
			cmd = scan.nextInt();
			if(cmd == 1) {
				System.out.println("Which game would you like to rent?");
				String game;
				game = scan.next();
				cafe.rentOutGame(game);
			}else if(cmd == 2) {
				System.out.println("Which game would you like to return?");
				String game;
				game = scan.next();
				cafe.returnGame(game);
			}else if(cmd == 3) {
				System.out.println("Which game would you like to repair?");
				String game;
				game = scan.next();
				cafe.repairGame(game);
			}else if(cmd == 4) {
				System.out.println("What is the name of game?");
				String gameName;
				gameName = scan.next();
				System.out.println("What is the price of game?");
				double gamePrice;
				gamePrice = scan.nextDouble();
				Game game = new Game(gameName, gamePrice);
				cafe.buyGame(game);
			}
		}
		scan.close();
		
	}

}
