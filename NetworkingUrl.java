import java.net.*;
import java.io.*;
class NetworkingUrl{
	public static void main(String args[])throws Exception{
		try{
			int i;
			URL url=new URL("http://www.google.com/javatutotial");
//			URL url=new URL("file:///D:/EDUCATION/PROGRAMMING/JAVA/soften/NetworkingUrl.java");

//==================================================================================

/*
			System.out.println("protocol: "+url.getProtocol());
			System.out.println("host: "+url.getHost());
			System.out.println("port: "+url.getPort());
			System.out.println("filename: "+url.getFile());
			
			URLConnection urlCon=url.openConnection();
			InputStream in=urlCon.getInputStream();
			
			while((i=in.read())!=-1){
				System.out.print((char)i);
			}
*/			


//===============================================================================
/*			HttpURLConnection httpCon=(HttpURLConnection)url.openConnection();
			for(i=0;i<8;i++){
			
				System.out.println(httpCon.getHeaderFieldKey(i)+" = "+httpCon.getHeaderField(i));
			}
			httpCon.disconnect();
*/
//===============================================================================

			InetAddress inetAddr=InetAddress.getLocalHost();
			System.out.println("local: "+inetAddr);
			System.out.println("local ip:  "+inetAddr.getHostAddress());
			System.out.println("local Name: "+inetAddr.getHostName());
			InetAddress inetAddr1=InetAddress.getByName("www.google.com"));
			
		}catch(Exception e){
			
		}
	}
}