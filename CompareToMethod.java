public class CompareToMethod{
	public static void main(String args[]){
		String s1="abc";
		String s2="abc";
		String s3=new String("pqr");
		System.out.println(s1.compareTo(s2));//s1=s2
		System.out.println(s1.compareTo(s3));//-ve bcz s1<s3
		System.out.println(s3.compareTo(s1));//+ve bcz s3>s1
	}
}