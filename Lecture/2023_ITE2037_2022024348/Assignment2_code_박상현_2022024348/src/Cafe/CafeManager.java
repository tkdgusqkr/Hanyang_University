package Cafe;

import java.util.Scanner;

public class CafeManager {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("What is the path of the gamesfile?");
		String filePath = scan.nextLine();
		CSVLoader csv = new CSVLoader();
		Game[] games = csv.loadGames(filePath);
		Cafe cafe = new Cafe(games, 5);
		while(true) {
			cafe.printCafeDetails();
			System.out.println("What would you like to do:");
			System.out.println("1: Rent a game, 2: Return a game, 3: Repair a game, 4: Buy a new game, 5: Save games");
			String cmd = scan.nextLine();
			if(cmd.equals("1")) {
				System.out.println("Which game would you like to rent?");
				String game = scan.nextLine();
				cafe.rentedOutGame(game);
			}else if(cmd.equals("2")) {
				System.out.println("Which game would you like to return?");
				String game = scan.nextLine();
				cafe.returnGame(game);
			}else if(cmd.equals("3")) {
				System.out.println("Which game would you like to repair?");
				String game = scan.nextLine();
				cafe.repairGame(game);
			}else if(cmd.equals("4")) {
				System.out.println("What is the name of game?");
				String name = scan.nextLine();
				System.out.println("What is the price of game?");
				String price = scan.nextLine();
				System.out.println("What is the type of game?");
				String type = scan.nextLine();
				if(type.equals("Board")) {
					BoardGame game = new BoardGame(name, Double.parseDouble(price), 100);
					cafe.buyGame(game);
				}else if(type.equals("Card")) {
					CardGame game = new CardGame(name, Double.parseDouble(price), 100);
					cafe.buyGame(game);
				}if(type.equals("Electronic")) {
					ElectronicGame game = new ElectronicGame(name, Double.parseDouble(price), 100);
					cafe.buyGame(game);
				}
			}else if(cmd.equals("5")) {
				System.out.println("What is the file you want to save to?");
				String file = scan.nextLine();
				csv.saveGames(cafe.getGame(), file);
				break;
				
			}
		}
		scan.close();
	}

}
