import java.io.*;
class CopyFile
{
	int i;
	public static void main(String args[])
	{	
		CopyFile ob=new CopyFile();
		try
		{
		FileInputStream fin=new FileInputStream("file1.txt");
		FileOutputStream fout=new FileOutputStream("file2.txt");
		do	
		{
			ob.i=fin.read();
			if(ob.i!=-1)
				fout.write(ob.i);
		}while(ob.i!=-1);
		fin.close();
		fout.close();	
		}
		catch(FileNotFoundException e)
		{}
		catch(IOException e1)
		{
		}
	}
}