public class StringOperations{
	public static void main(String args[]){
		String s=" alphabets ";
		System.out.println("string= "+s);
		System.out.println("lowercase= "+s.toLowerCase());
		System.out.println("uppercase= "+s.toUpperCase());
		System.out.println("trim= "+s.trim());
		System.out.println("if it ends with s  "+s.endsWith("s "));
		System.out.println("if starts with alp   "+s.startsWith(" alp"));
		System.out.println("char at 0: "+s.charAt(0));
		System.out.println("char at 9: "+s.charAt(9));
		System.out.println("length= "+s.length());
		System.out.println("replace= "+s.replace("pha"," "));


	}
}