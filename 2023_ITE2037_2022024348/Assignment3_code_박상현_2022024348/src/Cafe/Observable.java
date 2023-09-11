package Cafe;

public interface Observable {
	public void subscribe(Observer observer) throws InterruptedException;
	public void unsubscribe(Observer observer) throws InterruptedException;
}
