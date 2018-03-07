/*
 * Created on Apr 11, 2005
 *
 * Kernel of the Temperature Converter
 */
package temperatureconverter;

/**
 * @author Kaleem
 *
 *  This is the core class for temperature converter
 */
public class TempConverterEngine 
{
    public TempConverterEngine(){ /* Default constructore */}
    
    public double degreeToFahrenheit(double degree)
    {       
        /* Convert the temperature to Fahrenheit*/
        return (degree*1.80+32);
    }

    public double fahrenhietToDegree(double fah)
    {
        return (fah-32)/1.8;
    }
    
    public double degreeToKelvin(double deg)
    {
        return (deg+273);
    }
    
    public double kelvinToDegree(double kelvin)
    {
        return (kelvin-273);
    }
    
    public double fahrenheitToKelvin(double fah)
    {
        return (((fah-32)/1.8)+273);
    }

    public double kelvinToFahrenheit(double kel)
    {
        return ((kel-273)*1.80+32);
    }
}
