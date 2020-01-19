import java.util.*;
import java.io.*;
class Employee{
	int empno;
	String name;
	int age;
	Employee(int empno,String name,int age){
		this.empno=empno;
		this.name=name;
		this.age=age;
	}
}
class AgeComparator implements Comparator<Employee>{
	public int compare(Employee e1, Employee e2){
		if(e1.age==e2.age) 
			return 0; 
		else if(e1.age>e2.age) 
			return 1; 
		else return -1; 
	}
}
class NameComparator implements Comparator<Employee>{ 
	public int compare(Employee e1, Employee e2){
		return e1.name.compareTo(e2.name); 
	} 
}
class ComparatorSorting{ 
	public static void main(String args[]){
		ArrayList<Employee> al=new ArrayList<Employee>();
		al.add(new Employee(114,"Devu",25));
		al.add(new Employee(105,"Bini",26));
		al.add(new Employee(108,"Kripz",24));
		al.add(new Employee(108,"Kripz",24));
		System.out.println("Sorting by Name...");
		Collections.sort(al,new NameComparator());
		for(Employee emp: al){
			System.out.println(emp.empno+" "+emp.name+" "+emp.age);
		} 
		System.out.println("sorting by age..."); 
		Collections.sort(al,new AgeComparator());
		for(Employee emp: al){
			System.out.println(emp.empno+" "+emp.name+" "+emp.age); 
		}
	}
}