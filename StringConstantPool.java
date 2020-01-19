public class StringConstantPool{
	public static void main(String args[]){
		String str1="abc";
		String str2="abc";
		String str3=new String("abc");
		if(str1==str2){
			System.out.println("str1=str2");
		}
		else{
			System.out.println("str1!=str2");
		}
		if(str2==str3){
			System.out.println("str2=str3");
		}
		else{
			System.out.println("str2!=str3");
		}
	}
}