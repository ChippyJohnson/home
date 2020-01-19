import java.io.*;
class Student
{
	int rollno;
	BufferedReader br;
	void getnum()
	{	
		try
		{
		System.out.print("Enter the rollno: ");
		br=new BufferedReader(new InputStreamReader(System.in));
		rollno=Integer.parseInt(br.readLine());
		}
		catch(IOException e)
		{
		}
	}
	void putnum()
	{
		System.out.println("Rollno= "+rollno);
	}
}
class Test extends Student
{
	int mark1,mark2;
	void getmarks()
	{	try
		{
		br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter mark1: ");
		mark1=Integer.parseInt(br.readLine());
		System.out.print("Enter mark2: ");
		mark2=Integer.parseInt(br.readLine());
		}
		catch(IOException e)
		{
		}
	}
	void putmarks()
	{
		System.out.println("mark1= "+mark1);
		System.out.println("mark2= "+mark2);
	}
}

class Result extends Test implements Sports
{
	int totalmarks;
	void totalMarks()
	{
		totalmarks=sportsmark+mark1+mark2;
		System.out.println("Total marks= "+totalmarks);
	}
	public static void main(String args[])
	{
		Result r=new Result();
		r.getnum();
		r.getmarks();	
		r.putnum();
		r.putmarks();
		r.totalMarks();
		
	}
}