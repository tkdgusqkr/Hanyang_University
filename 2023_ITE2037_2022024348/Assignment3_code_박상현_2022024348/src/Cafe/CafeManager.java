package Cafe;

import java.util.Scanner;

public class CafeManager {
	private static double money = 5;
	private static GameCorner gc;
	private static CoffeeCorner cc;
	private static CSVLoader csv;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("What is the path of the gamesfile?");
		String filePath = scan.nextLine();
		csv = new CSVLoader();
		gc = new GameCorner(csv.loadGames(filePath));
		cc = new CoffeeCorner(2);
		while(money >= 0) {
			System.out.println(money);
			gc.printCafeDetails();
			System.out.println("What would you like to do:");
			System.out.println("1: Rent a game, 2: Return a game, 3: Repair a game, 4: Buy a new game, 5: Save games, 6: Buy coffee");
			String cmd = scan.nextLine();
			if(cmd.equals("1")) {
				System.out.println("Which game would you like to rent?");
				String game = scan.nextLine();
				money += gc.rentOutGame(game);
			}else if(cmd.equals("2")) {
				System.out.println("Which game would you like to return?");
				String game = scan.nextLine();
				gc.returnGame(game);
			}else if(cmd.equals("3")) {
				System.out.println("Which game would you like to repair?");
				String game = scan.nextLine();
				money -= gc.repairGame(game);
			}else if(cmd.equals("4")) {
				System.out.println("What is the name of game?");
				String name = scan.nextLine();
				System.out.println("What is the price of game?");
				String price = scan.nextLine();
				System.out.println("What is the type of game?");
				String type = scan.nextLine();
				if(type.equals("Board")) {
					BoardGame game = new BoardGame(name, Double.parseDouble(price), 100);
					gc.buyGame(game);
				}else if(type.equals("Card")) {
					CardGame game = new CardGame(name, Double.parseDouble(price), 100);
					gc.buyGame(game);
				}if(type.equals("Electronic")) {
					ElectronicGame game = new ElectronicGame(name, Double.parseDouble(price), 100);
					gc.buyGame(game);
				}
				money -= Double.parseDouble(price);
			}else if(cmd.equals("5")) {
				System.out.println("What is the file you want to save to?");
				String file = scan.nextLine();
				csv.saveGames(gc.getGame(), file);
				break;
			}else if(cmd.equals("6")) {
				System.out.println("What kind of coffee do you want?");
				cc.listCoffeeTypes();
				String type = scan.nextLine();
				money += cc.makeCoffee(type);
			}
		}
		scan.close();
	}

}
