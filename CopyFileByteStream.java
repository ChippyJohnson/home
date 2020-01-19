import java.io.*;
class CopyFileByteStream{
	public static void main(String[] args) {
		int cit;
		FileInputStream fin=null;
		FileOutputStream fout=null;
		try{
			fin=new FileInputStream("city.txt");//to take bytes from city.txt
			fout=new FileOutputStream("country.txt");//to store bytes to country.txt
			while((cit=fin.read())!=-1)//until we get null while reading city.txt
				fout.write(cit);//write each one to country.txt
		}
		catch(IOException e){
			System.out.println(e);
			System.exit(0);
		}
		finally{//to not to exit when an exception comes
			try{
				fin.close();
				
				fout.close();
			}
			catch(IOException e1){
				System.out.println(e1);
			}
		}
	}
}