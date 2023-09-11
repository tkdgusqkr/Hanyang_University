package lab10;

public class Dog extends Animal implements Barkable {
	public Dog(String name) {
		super(name);
	}
	public String bark() {
		return "Bowwow";
	}
}
