import java.util.StringTokenizer;
public class StringReverse{
	public static void main(String[] args) {
		String str="hello world hai";
		StringTokenizer st=new StringTokenizer(str," ");
		String reverse=" ";
		while(st.hasMoreTokens()){
			reverse=st.nextToken()+" "+reverse;
		}
		System.out.println(reverse);
	}
}