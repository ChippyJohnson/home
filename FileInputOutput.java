import java.io.*;
class FileInputOutput{
	public static void main(String[] args) {
		byte cities[]={'a','b','c','d','e','f'};
		int cit;
	//	FileOutputStream fout=null;
		try{
			FileOutputStream fout=new FileOutputStream("city.txt");
			fout.write(cities);
			FileInputStream fin=new FileInputStream("city.txt");
			while((cit=fin.read())!=-1)
				System.out.print((char)cit);
	
			fout.close();
		}
		catch(IOException e){
			System.out.println(e);
			System.exit(0);
		}
	}
}