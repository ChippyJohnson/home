class MyThread extends Thread{
	MyThread(){
		super("Demo thread");
		System.out.println("child thread "+this);
		start();
	}
	public void run(){
		try{
			for(int i=5;i>0;i--){
				System.out.println("child thread "+i);
				Thread.sleep(500);
			}
		}
		catch(InterruptedException e){
			System.out.println("child interrupt");
		}
		System.out.println("exiting child thread");
	}
}
class ExtendingThread{
	public static void main(String args[]){
		new MyThread();
		try{
			for(int i=5;i>0;i--){
				System.out.println("main thread "+i);
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e){
			System.out.println("main interrupted");
		}
		System.out.println("main thread exiting");
	}
}