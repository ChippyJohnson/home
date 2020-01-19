import java.applet.*;
import java.awt.*;
/*
<applet  code="ParamDemo" width=300  height=300>
<param name="message" value="chippy"/>
<param name="x" value="150"/>
<param name="y" value="120"/>
</applet>
*/
public class ParamDemo extends Applet
{
	String msg;	
	int x,y;
	public void start()
	{
		msg=getParameter("message");
		x=Integer.parseInt(getParameter("x"));
		y=Integer.parseInt(getParameter("y"));
		
	}
	public void paint(Graphics g)
	{
		g.drawString(msg,x,y);
	}
}