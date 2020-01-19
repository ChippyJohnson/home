import java.io.*;
class Student implements Serializable{
	int id;
	String name;
	public Student(int id,String name){
		this.id=id;
		this.name=name;
	}
	public void display(){
		System.out.println("id= "+id+"\nname= "+name);
	}
}
class ObjectStream{
	public static void main(String args[])throws Exception{
		try{
			Student s=new Student(111,"Sharu");
			FileOutputStream fout=new FileOutputStream("objectstreamfile.txt");
			FileInputStream fin=new FileInputStream("objectstreamfile.txt");
			ObjectOutputStream oout=new ObjectOutputStream(fout);
			ObjectInputStream oin=new ObjectInputStream(fin);
			oout.writeObject(s);
			Student s1=(Student)oin.readObject();
			s1.display();
			oin.close();
			//oout.close();
		}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
