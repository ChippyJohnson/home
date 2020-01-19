import java.util.Date;
import java.text.*;
class DateFormatting{
	public static void main(String args[]){
		SimpleDateFormat dateForm=new SimpleDateFormat("dd:mm:yyyy");
		Date date1=null, date2=null, date3=null;
		Date date =new Date();
		try{
			date1=dateForm.parse("2:07:07");
			date2=dateForm.parse("8:07:07");
			System.out.println(dateForm.format(date));
		}
		catch(ParseException e){
			e.printStackTrace();
		}
		System.out.println(date1);
		System.out.println(date2);
		System.out.println(date3);
		if(date1.after(date2)){
			System.out.println(date1+" is after "+date2);
		}
		if(date1.before(date2)){
			System.out.println(date1+" is before "+date2);
		}
		if(date1.equals(date2)){
			System.out.println(date1+" is equals to "+date2);
		}
		
	}
}