public class InternMethod{
	public static void main(String args[]){
		String s1=new String("abc");
		String s2="abc";
		if(s1==s2)
			System.out.println("s1 and s2 are equal");
		else
			System.out.println("s1 and s2 are not equal");
		s1=s1.intern();
		if(s1==s2)
			System.out.println("s1 and s2 are equal");
		else
			System.out.println("s1 and s2 are not equal");

	}
}