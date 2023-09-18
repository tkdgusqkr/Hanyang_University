package lab10;

public class Tiger extends Animal implements Barkable {
	public Tiger(String name) {
		super(name);
	}
	public String bark() {
		return "Growl";
	}
}
