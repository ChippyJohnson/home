public class EqualsComparison{
	public static void main(String args[]){
		String s1="abc";
		String s2="abc";
		String s3=new String("abc");
		String s4="pqr";
		System.out.println(s1.equals(s2));
		System.out.println(s1.equals(s3));
		System.out.println(s1.equals(s4));
	}
}