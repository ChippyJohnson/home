import java.util.regex.Matcher;
import java.util.regex.Pattern;

class RegexExample{
	public static void main(String[] args) {
		Pattern pattern=Pattern.compile("ab",Pattern.CASE_INSENSITIVE);
		Matcher matcher=pattern.matcher("ABcabdAb");
		while(matcher.find()){
			System.out.println("found the text\""+matcher.group()+"\"starting at "+matcher.start()+" index and ending at index "+matcher.end());
		}
		pattern=Pattern.compile("\\W");
		String[] words=pattern.split("one@two#three:four$five");
		for(String s:words){
			System.out.println("split using pattern.split(): "+s);
		}
		pattern=Pattern.compile("1*2");
		matcher=pattern.matcher("11234512678");
		System.out.println("Using replaceAll: "+matcher.replaceAll("_"));
		System.out.println("using replacefirst: "+matcher.replaceFirst("_"));
	}
}