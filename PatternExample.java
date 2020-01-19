import java.util.regex.*;
class PatternExample{
	public static void main(String args[]){
		Pattern pattern=Pattern.compile(".xx.");
		Matcher matcher=pattern.matcher("mxxy");
		System.out.println("input string matches reg exp= "+matcher.matches());
		pattern=Pattern.compile("*xx*");
	}
}