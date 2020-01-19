class Circle
{
	public static void main(String args[])
	{
		double r,pi=3.14,area=0,circum=0;
		//r=Integer.parseInt(args[0]);
		r=10;
		area=pi*r*r;
		circum=2*pi*r;
		System.out.println("area= "+area+"\ncircumference= "+circum);
	}
}