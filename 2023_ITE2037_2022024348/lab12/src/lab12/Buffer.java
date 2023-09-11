package lab12;

public class Buffer {
	private int loc = 0;
	private double[] data;
	Buffer(int size){
		this.data = new double[size];
		System.out.println("New buffer");
		System.out.println(this);
	}
	//data의 개수 반환
	public int getSize() {
		return this.data.length;
	}
	//loc를 이용해 buffer가 가득 찬 상태인지 while문을 통해 체트하며 만약 가즉 찬 경우 wait()를 통해 buffer 차단
	//만약 while이 아닌 if문을 사용하면 조건이 충족하지 않는 경우 스레드가 해당 함수나 블록을 빠져나가 wait(), notifyAll() 등을 구현할 수 없다.
	synchronized void add(double toAdd) throws InterruptedException {
		while(loc >= this.data.length) {
			System.out.println("Buffer is full");
			wait();
		}
		System.out.println("Producer# Adding item on : " + this.loc + ": " + toAdd);
		this.data[this.loc] = toAdd;
		this.loc += 1;
		System.out.println(this);
		System.out.flush();
		notifyAll();
	}
	//buffer가 비었는지 체크하며 data를 줄여준다.
	//만약 while이 아닌 if문을 사용하면 조건이 충족하지 않는 경우 스레드가 해당 함수나 블록을 빠져나가 wait(), notifyAll() 등을 구현할 수 없다.
	synchronized double remove() throws InterruptedException {
		while(loc <= 0) {
			System.out.println("Consumer#" + " O Buffer is empty.\n");
			wait();
		}
		double temp = this.data[this.loc - 1];
		System.out.println("Consumer#" + "Removing item on " + this.loc + ": " + temp);
		this.data[this.loc - 1] = 0.0;
		this.loc -= 1;
		System.out.println(this);
		System.out.flush();
		notifyAll();
		return temp;
	}
	//data를 출력하는 함수
	public synchronized String toString() {
		String toReturn = "";
		for(double d: data) {
			toReturn += String.format("%5.2f", d) + " ";
		}
		return toReturn;
	}
}
