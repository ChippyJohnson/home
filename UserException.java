import java.io.*;
class MyException extends Exception
{
	private int n;
	MyException(int a)
	{
		n=a;
	}
	public String toString()
	{
		return "My-Exception["+n+"]";
	}
}
class UserException
{
	static void compute(int a)throws MyException
	{
		if(a>150)
		{
			throw new MyException(a);
		}
		System.out.println("Successfull");
	}
	public static void main(String args[])
	{
		int a;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		try
		{	System.out.print("Enter the quantity of bikes you need: ");
			a=Integer.parseInt(br.readLine());
			compute(a);
		}
		catch(MyException e)
		{
			System.out.print("Enter the quantity less than 150: ");
			try
			{
				a=Integer.parseInt(br.readLine());
				compute(a);
			}
			catch(Exception io)
			{
			}
			
		}
		catch(Exception io)
			{
			}
		
	}
}
