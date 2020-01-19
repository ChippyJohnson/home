import java.util.*;
class Book{
	int id,price;
	String name;
	Book(int id,String name,int price){
		this.id=id;
		this.name=name;
		this.price=price;
	}
}
class HashTable{
	public static void main(String args[]){
		Map<Integer,Book> map=new Hashtable<Integer,Book>();
		Book b1=new Book(101,"wings of fire",500);
		Book b2=new Book(102,"wings",50);
		Book b3=new Book(10332,"fire",5400);
		map.put(1,b1);
		map.put(2,b2);
		map.put(3,b3);
		for(Map.Entry<Integer,Book> entry:map.entrySet()){
			int key=entry.getKey();
			Book b=entry.getValue();
			System.out.println("key "+key+" details .... "+b.id+" "+b.name+" "+b.price);
		}
	}
}