package lab12;

public class ProdCons {
	private Buffer buffer;
	private Producer[] producer;
	private Consumer[] consumer;
	//생성자
	ProdCons(){
		this.buffer = new Buffer(5);
		this.producer = new Producer[2];
		this.consumer = new Consumer[2];
		this.producer[0] = new Producer(this.buffer);
		this.consumer[0] = new Consumer(this.buffer);
		this.producer[1] = new Producer(this.buffer);
		this.consumer[1] = new Consumer(this.buffer);
	}
	//Thread를 상속받는 class를 ProdCons 속에 inner class로 만든다.
	private class Producer extends Thread {
		private final Buffer buffer;
		public Producer(Buffer buffer) {
			this.buffer = buffer;
		}
		//buffer 속에 data를 추가하는 함수
		public void producer() throws InterruptedException {
			for(int i = 0;i < this.buffer.getSize();++i) {
				System.out.println("Producer#" + ":" + this);
				this.buffer.add(Math.random() * 100);
			}
		}
		//예외처리를 통해 producer()를 실행시키는 함수
		public void run() {
			try {
				this.producer();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	//Thread를 상속받는 class를 ProdCons 속에 inner class로 만든다.
	private class Consumer extends Thread {
		private final Buffer buffer;
		public Consumer(Buffer buffer) {
			this.buffer = buffer;
		}
		//buffer 속에 data를 제거하는 함수
		public void consume() throws InterruptedException {
			for(int i = 0;i < this.buffer.getSize();++i) {
				System.out.println("Consumer#" + ":" + this);
				this.buffer.remove();
			}
		}
		//예외처리를 통해 consume()를 실행시키는 함수
		public void run() {
			try {
				this.consume();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	//Thread를 모두 start()하는 함수
	void startThread() {
		this.producer[0].start();
		this.consumer[0].start();
		this.producer[1].start();
		this.consumer[1].start();
	}
}
