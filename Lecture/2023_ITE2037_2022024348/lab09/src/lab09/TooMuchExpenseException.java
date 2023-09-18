package lab09;

public class TooMuchExpenseException extends Exception {
	private int inputNum;
	public TooMuchExpenseException(){
		super("Not enough balance.");
	}
	public TooMuchExpenseException(int num){
		super("Over the limit!");
		this.inputNum = num;
	}
	public int getInputNum() {
		return inputNum;
	}
}
