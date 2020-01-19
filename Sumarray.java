class Sumarray
{
	public static void main(String args[])
	{
		int a[]={3,4,2,1,1},n,s=0,i;
		n=a.length;
		for(i=0;i<n;i++)
			s=s+a[i];
		System.out.println("sum= "+s);
		System.out.println("array length= "+n);
	}
}