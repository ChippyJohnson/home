import java.io.*;
class Student implements Serializable{
	int id;
	String name;
	public Student(int id,String name){
		this.id=id;
		this.name=name;
	}
	public void display(){
		System.out.println("id= "+id+"\n name= "+name);
	}
}
class ObjectStreamInput{
	public static void main(String args[])throws Exception{
		try{
			FileInputStream fin=new FileInputStream("objectstreamfile.txt");
			ObjectInputStream oin=new ObjectInputStream(fin);
			Student s1=(Student)oin.readObject();
			s1.display();
			oin.close();
		}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
