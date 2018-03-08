public class testDLLCall
{
    public static void main(String[] args)
    {
        System.out.println("Before Calling DLL");
	new testDLLCall().cPrintf();
        System.out.println("After Calling DLL");
    }
    
    public native void cPrintf();
    static
    {
	    System.loadLibrary("testC_JavaLink");
    }
}


