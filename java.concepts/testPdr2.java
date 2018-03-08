class Pdr {
    int Pdr_Val;

    public Pdr(String controllerName)
    {
        System.out.println("timing calculation for " + controllerName);
    }
    public void setPDR(String description, int pdr_value)
    {
        Pdr_Val = pdr_value;
        System.out.println("PDR value for " + description + "kbps =\t" + Pdr_Val);
    }
    public byte calculateBRP()
    {
        byte field;
        field = (byte)(Pdr_Val & 0x003F);
        System.out.println("BRP =\t" + field);
        return (field);
    }

    public byte calculateSJW()
    {
        byte field;
        field = (byte)(Pdr_Val & 0x00C0);
        System.out.println("SJW =\t" + field);
        return (field);
    }

    public byte calculateTSEG1()
    {
        byte field;
        field = (byte)((Pdr_Val & 0x0F00) >> 8);
        System.out.println("TSEG1 =\t" + field);
        return (field);
    }

    public byte calculateTSEG2()
    {
        byte field;
        field = (byte)((Pdr_Val & 0x7000) >> 8);
        System.out.println("TSEG2 =\t" + field);
        return (field);
    }
}

public class testPdr2
{
    final static int PDR_VAL_COUNT=5;
    public static void main(String args[])
    {
        int pdr_list[] =
                           {0x7AC9,
                            0x7AC3,
                            0x7AC1,
                            0x7AC0,
                            0x25C0
                           };

        int pdr_desc[] =
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
            c167.setPDR(Integer.toString(pdr_desc[i]), pdr_list[i]);
            c167.calculateBRP();
            c167.calculateSJW();
            c167.calculateTSEG1();
            c167.calculateTSEG2();
        }

    }

}



