package Cafe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class CSVLoader {
	public ArrayList<Game> loadGames(String fileName) {
		//Count the number of games
		int lineCount = 0;
		try {
			BufferedReader reader = new BufferedReader(new FileReader(fileName));
			while(reader.readLine() != null) {
				lineCount += 1;
			}
			reader.close();
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			e.printStackTrace();
		}
		if(lineCount != 0) {
			ArrayList<Game> games = new ArrayList<Game>();
			try {
				//Read the file by using Buffer
				BufferedReader inputStream = new BufferedReader(new FileReader(fileName));
				String line;
				for(int i = 0;(line = inputStream.readLine()) != null;++i) {
					//Split the line by "," because the file is separated with ","
					String[] split = line.split(",");
					//Distinguish by game type
					if(split[0].equals("Board")) {
						games.add(new BoardGame(split[1], Double.parseDouble(split[2]), Integer.parseInt(split[3])));
					}else if(split[0].equals("Card")) {
						games.add(new CardGame(split[1], Double.parseDouble(split[2]), Integer.parseInt(split[3])));
					}else if(split[0].equals("Electronic")) {
						games.add(new ElectronicGame(split[1], Double.parseDouble(split[2]), Integer.parseInt(split[3])));
					}
				}
				inputStream.close();
			}catch(FileNotFoundException e) {
				e.printStackTrace();
			}catch(IOException e) {
				e.printStackTrace();
			}
			return games;
		}else {
			return null;
		}
	}
	public void saveGames(ArrayList<Game> games, String fileName) {
		File file = null;
		try {
			file = new File(fileName);
			BufferedWriter outputStream = new BufferedWriter(new FileWriter(file));
			for(int i = 0;i < games.size();++i) {
				if(games.get(i) instanceof BoardGame) {
					outputStream.write("Board");
				}else if(games.get(i) instanceof CardGame) {
					outputStream.write("Card");
				}else if(games.get(i) instanceof ElectronicGame) {
					outputStream.write("Electronic");
				}
				outputStream.write("," + games.get(i).getName() + "," + games.get(i).getPrice() + "," + games.get(i).quality);
				outputStream.write(System.lineSeparator());
			}
			System.out.println("Game saved successfully");
			outputStream.close();
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
