import java.util.ArrayList;
class Monkey{
	int a;
	Monkey(){
		a=5;
	}
}
class ArrayListOperations{
	public static void main(String args[]){
/*		Monkey A=new Monkey();
		Monkey B=new Monkey();
		Monkey C=new Monkey();
		Monkey D=new Monkey();
		Monkey E=new Monkey();
		Monkey P=new Monkey();
		ArrayList arraylist=new ArrayList();
		System.out.println("initial size of arraylist: "+arraylist.size());
		arraylist.add(A);
		arraylist.add(B);
		arraylist.add(C);
		arraylist.add(D);
		arraylist.add(E);
		System.out.println("size of array after adding elements: "+arraylist.size());
		System.out.println("contents of arraylist: "+arraylist);
		arraylist.add(2,P);
		System.out.println("contents of arraylist(added 'p' at position 2): "+arraylist);
		arraylist.remove(3);
		arraylist.remove(A);
		System.out.println("contents of arraylist(removeed index 3 and element A): "+arraylist);
*/
		ArrayList arraylist=new ArrayList();
		System.out.println("initial size of arraylist: "+arraylist.size());
		arraylist.add("A");
		arraylist.add("B");
		arraylist.add("C");
		arraylist.add("D");
		arraylist.add("E");
		System.out.println("size of array after adding elements: "+arraylist.size());
		System.out.println("contents of arraylist: "+arraylist);
		arraylist.add(2,"P");
		arraylist.add(6,"O");
		System.out.println("contents of arraylist(added 'p' at position 2 and pos 6): "+arraylist);
		arraylist.remove(3);
		arraylist.remove("A");
		System.out.println("contents of arraylist(removeed index 3 and element A): "+arraylist);
	}
}