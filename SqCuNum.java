import java.io.*;
import sqcu.*;
class SqCuNum
{
	int sno,cno,no;
	public static void main(String args[])
	{
		try
		{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		SqCuNum sc=new SqCuNum();
		SqCu scp=new SqCu();
		System.out.print("Enter the no: ");
		sc.no=Integer.parseInt(br.readLine());
		sc.sno=scp.square(sc.no);
		sc.cno=scp.cube(sc.no);
		System.out.println("square= "+sc.sno+"\ncube= "+sc.cno);
		}
		catch(IOException e)
		{
		}
	}
}