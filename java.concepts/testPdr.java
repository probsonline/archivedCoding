public class testPdr
{
    final static int PDR_VAL_COUNT=5;
    public static void main(String args[])
    {
        int pdr_list[PDR_VAL_COUNT] =
                           {0x7AC9,
                            0x7AC3,
                            0x7AC1,
                            0x7AC0,
                            0x25C0
                           };

        int pdr_desc[PDR_VAL_COUNT] =
                           {50,
                            125,
                            250,
                            500,
                            1000
                           };

        System.out.println("Welcome again to java after years and years");

        Pdr c167 = new Pdr("Simemes c167");
        for(int i=pdr_list.length-1; i>=0; i--)
        {
            c167.setPDR(pdr_desc, pdr_list);
            c167.calculateBRP();
            c167.calculateSJW();
            c167.calculateTSEG1();
            c167.calculateTSEG2();
        }
    }
}



