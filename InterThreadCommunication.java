//producer consumer problem
class Q{
	int n;
	boolean valueset=false;
	synchronized int get(){
		while(!valueset){
			try{
				wait();
				Thread.sleep(500);
			}
			catch(InterruptedException e){
				System.out.println("*******interrupted exception caught******"+e);
				
			}
		}
		System.out.println("get "+n);
		valueset=false;
		notify();
		return n;
	}
	synchronized void put(int n){
		while(valueset){
			try{
				wait();
				Thread.sleep(500);
			}
			catch(InterruptedException e){
				System.out.println("*******interrupted exception caught******"+e);
				
			}
		}
		this.n=n;
		System.out.println("put "+n);
		valueset=true;
		notify();
	}
}
class Producer implements Runnable{
	Q q;
	Producer(Q q){
		this.q=q;
		new Thread(this,"producer").start();
	}
	public void run(){
		int i=0;
		while(true){
			q.put(i++);
		}
	}
}
class Consumer implements Runnable{
	Q q;
	Consumer(Q q){
		this.q=q;
		new Thread(this,"consumer").start();
	}
	public void run(){
		while(true){
			q.get();
		}
	}
}

class InterThreadCommunication{
	public static void main(String args[]){
		Q q=new Q();
		new Producer(q);
		new Consumer(q);
		System.out.println("=======press ctrl+c to STOP==========");
	}
}