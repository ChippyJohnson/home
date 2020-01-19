import java.io.*;
class FileOutputStreamWriteBytes{
	public static void main(String[] args) {
		byte cities[]={'a','b','c','d','e'};
	//	FileOutputStream fout=null;
		try{
			FileOutputStream fout=new FileOutputStream("city.txt");
			fout.write(cities);
			fout.close();
		}
		catch(IOException e){
			System.out.println(e);
			System.exit(0);
		}
	}
}