package lab07;

public class Language {
	protected String name;
	protected int numSpeakers;
	protected String regionsSpoken;
	protected String wordOrder;
	public Language(String name, int numSpeakers, String regionsSpoken, String wordOrder) {
		this.name = name;
		this.numSpeakers = numSpeakers;
		this.regionsSpoken = regionsSpoken;
		this.wordOrder = wordOrder;
	}
	public void getInfo() {
		System.out.println(this.name + " is spoken by " + this.numSpeakers + " people mainly in " + this.regionsSpoken);
		System.out.println("The language follows the word order: " + this.wordOrder);
	}
	public static void main(String[] args) {
		System.out.println("---------- Language ----------");
		Language spanish = new Language("Spanish", 555000000, "Spain, Latin America, and Equatorial Guinea", "subject-verb-object");
		spanish.getInfo();
		System.out.println("----------Koreanic----------");
		Language korean = new Koreanic("Korean", 80400000);
		korean.getInfo();
		Language jeju_uh = new Koreanic("Jeju Language", 695500);
		jeju_uh.getInfo();
		System.out.println("----------Mayan----------");
		Mayan kiche = new Mayan("Ki'che'", 2330000);
		kiche.getInfo();
	}
}
