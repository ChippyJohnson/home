class Calculator
{
	public static void main(String args[])
	{
		double a,b,r=0;
		String c;
		c=args[0];
		a=Integer.parseInt(args[1]);
		b=Integer.parseInt(args[2]);	
		switch(c)
		{
		case "add":
		{
			r=a+b;
			break;	
		}
		case "sub":
		{
			r=a-b;
			break;	
		}
		case "mul":
		{
			r=a*b;
			break;	
		}
		case "div":
		{
			r=a/b;
			break;	
		}
		default:
			System.out.println("wrong choice");
		}
		System.out.println("result= "+r);
	}
}