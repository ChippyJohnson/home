import java.io.*;
class FileInputStreamReadBytes{
	public static void main(String[] args) {
		int cities;
		try{
			FileInputStream fin=new FileInputStream("city.txt");
			while((cities=fin.read())!=-1){
				System.out.print((char)cities);
			}
			fin.close();
		}
		catch(IOException e){
			System.out.println(e);
			System.exit(0);
		}
	}
}