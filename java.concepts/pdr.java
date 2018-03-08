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
        field = Pdr_Val & 0x003F;
        System.out.println("BRP =\t" + field);
        return (field);
    }

    public byte calculateSJW()
    {
        byte field;
        field = Pdr_Val & 0x00C0;
        System.out.println("SJW =\t" + field);
        return (field);
    }

    public byte calculateTSEG1()
    {
        byte field;
        field = Pdr_Val & 0x0F00;
        System.out.println("TSEG1 =\t" + field);
        return (field);
    }

    public byte calculateTSEG2(INT pdr_val)
    {
        byte field;
        field = Pdr_Val & 0x7000;
        System.out.println("TSEG2 =\t" + field);
        return (field);
    }
}


