/**
 * <p>Title: ConverterEngine</p>
 *
 * <p>Description: coordinate conversion system's core</p>
 *
 * <p>Copyright: Copyright (c) 2016</p>
 *
 * <p>Company: Waseem</p>
 *
 * @waseem not attributable
 * @version 1.0
 */

import java.text.DecimalFormat;

public class ConverterEngine {

    double a,b,c;

    public ConverterEngine()
    {
    }

    DecimalFormat fmt=new DecimalFormat("0.###");

    //Converts Degree to Radian

    public double DegToRad(double d)
    {
       double r=d/180;
       return (r*Math.PI);
    }

    //Converts Radian to Degree

    public double RadToDeg(double r)
    {
       double d=r*180;
       return (d/Math.PI);
    }

    //This method converts Rectangular co-ordinates
    //to Cylinderical co-ordinates.

    public void ReToCy(double x,double y,double z)
    {
       //Finding a which is Rho

       double d=x*x;
       double e=y*y;

       a=Math.sqrt(d+e);

       //Finding c which is z

       c=z;

       //Finding b which is Phi

       b=RadToDeg(Math.atan(y/x));

       System.out.println("Value of Rho:"+fmt.format(a));
       System.out.println("Value of Phi:"+fmt.format(b));
       System.out.println("Value of z:"+fmt.format(c));
    }

    //This method converts Rectangular co-ordinates
    //to Spherical co-ordinates

    public void ReToSp(double x,double y,double z)
    {
       //Finding a which is r

       double d=x*x;
       double e=y*y;
       double f=z*z;

       a=Math.sqrt(d+e+f);

       //Finding b which is Theta
       //and limiting it b/w 0 to 180 degree

       b=RadToDeg(Math.acos(z/a));
       while(b>180){
          b=b-180;
       }

       //Finding c which is Phi

       c=RadToDeg(Math.atan(y/x));

       System.out.println("Value of r:"+fmt.format(a));
       System.out.println("Value of Theta:"+fmt.format(b));
       System.out.println("Value of Phi:"+fmt.format(c));
    }

    //This method converts Cylinderical co-ordinates
    //to Rectangular co-ordinates

    public void CyToRe(double x,double y,double z)
    {
       //Here x is Rho,y is Phi,z is z
       //Finding a which is x

       a=x*Math.cos(DegToRad(y));

       //Finding b which is y

       b=x*Math.sin(DegToRad(y));

       //Finding c which is z

       c=z;

       System.out.println("Value of x:"+fmt.format(a));
       System.out.println("Value of y:"+fmt.format(b));
       System.out.println("Value of z:"+fmt.format(c));
    }

    //This method converts Cylinderical co-ordinates
    //to Spherical co-ordinates
    public void CyToSp(double x,double y,double z)
    {
       //Here x is Rho,y is Phi,z is z
       //Finding a which is r

       double d=x*x;
       double e=z*z;

       a=Math.sqrt(d+e);

       //Finding b which is Theta
       //and limiting it b/w 0 to 180 degree

       b=RadToDeg(Math.acos(z/a));
       while(b>180){
          b=b-180;
       }

       //Finding c which is Phi

       c=y;
       System.out.println("Value of r:"+fmt.format(a));
       System.out.println("Value of Theta:"+fmt.format(b));
       System.out.println("Value of Phi:"+fmt.format(c));
    }

    //This method converts Spherical co-ordinates
    //to Rectangular co-ordinates

    public void SpToRe(double x,double y,double z)
    {
       //Here x is r,y is Theta,z is Phi
       //Finding a which is x

       a=x*Math.sin(DegToRad(y))*Math.cos(DegToRad(z));

       //Finding b which is y

       b=x*Math.sin(DegToRad(y))*Math.sin(DegToRad(z));

       //Finding c which is z

       c=x*Math.cos(DegToRad(y));

       System.out.println("Value of x:"+fmt.format(a));
       System.out.println("Value of y:"+fmt.format(b));
       System.out.println("Value of z:"+fmt.format(c));
    }

    //This method converts Spherical co-ordinates
    //to Cylinderical co-ordinates

    public void SpToCy(double x,double y,double z)
    {
       //Here x is r,y is Theta,z is Phi
       //Finding a which is Rho

       a=x*Math.sin(DegToRad(y));

       //Finding b which is Rho

       b=z;

       //Finding c which is z

       c=x*Math.cos(DegToRad(y));

       System.out.println("Value of Rho:"+fmt.format(a));
       System.out.println("Value of Phi:"+fmt.format(b));
       System.out.println("Value of z:"+fmt.format(c));
    }

}
