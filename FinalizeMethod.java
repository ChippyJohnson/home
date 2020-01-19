class finalizeMethod
{
    public static void main(String[] args)
    {
        finalizeMethod t = new finalizeMethod();
        System.out.println(t.hashCode());
 
        t = null;
 
        // calling garbage collector 
        System.gc();
 
        System.out.println("end");
    }
 
    @Override
    protected void finalize()
    {
        System.out.println("finalize method called");
    }
}