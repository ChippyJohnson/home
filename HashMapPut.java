import java.util.HashMap;
import java.util.Scanner;
class HashMapPut{
	public static void main(String args[])throws InterruptedException{
		HashMap<Integer,String> hashMap=new HashMap<>();
		String repeat;
		Scanner scanner=new Scanner(System.in);
		do{
			System.out.print("enter id: ");
			Integer idNum=Integer.parseInt(scanner.nextLine());
			System.out.print("enter name: ");
			String name=scanner.nextLine();
			String oldVal=hashMap.put(idNum,name);
			if(oldVal!=null){
				System.out.println(" id num "+idNum+" is over written by "+name+" instead of "+oldVal);
			}
			System.out.print("continue? ");
			repeat=scanner.nextLine();
		}
		while(repeat.equals("y"));
		System.out.println("==============================================");
		System.out.println("id\tName");
		for(int id:hashMap.keySet()){
			System.out.println(id+"\t"+hashMap.get(id));
		}
		System.out.println("==============================================");
		
	}
}