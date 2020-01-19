import java.io.*;
class CharStreamFileReaderWriter{
	public static void main(String args[]){
		File infile=new File("input.txt");
		File outfile=new File("output.txt");
		FileReader ins=null;
		FileWriter outs=null;
		try{
			ins=new FileReader(infile);
			outs=new FileWriter(outfile);
			int ch;
			while((ch=ins.read())!=-1)
				outs.write(ch);
		}
		catch(IOException e){
			System.out.println(e);
		}
		finally{
			try{
				ins.close();
				outs.close();
			}
			catch(IOException e){
				System.out.println(e);
			}
		}
	}
}
