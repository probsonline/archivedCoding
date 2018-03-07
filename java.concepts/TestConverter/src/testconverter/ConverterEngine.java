package testconverter;

import java.text.DecimalFormat;

public class ConverterEngine {
    private double X, Y, Z, R, PHI, RHO, THETA;

    public ConverterEngine(){}

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

       RHO=Math.sqrt(x*x+y*y);

       //Finding c which is z

       Z=z;

       //Finding b which is Phi

       PHI=RadToDeg(Math.atan(y/x));

       System.out.println("Value of Rho:"+fmt.format(RHO));
       System.out.println("Value of Phi:"+fmt.format(PHI));
       System.out.println("Value of z:"+fmt.format(Z));

    }

    //This method converts Rectangular co-ordinates
    //to Spherical co-ordinates
    public void ReToSp(double x,double y,double z)
    {
       //Finding a which is r

       double d=x*x;
       double e=y*y;
       double f=z*z;

       R=Math.sqrt(d+e+f);

       //Finding b which is Theta
       //and limiting it b/w 0 to 180 degree

       THETA=RadToDeg(Math.acos(z/R));
       while(THETA>180){
          THETA-=180;
       }

       //Finding c which is Phi

       PHI=RadToDeg(Math.atan(y/x));

       System.out.println("Value of r:"+fmt.format(R));
       System.out.println("Value of Theta:"+fmt.format(THETA));
       System.out.println("Value of Phi:"+fmt.format(PHI));
    }

    //This method converts Cylinderical co-ordinates
    //to Rectangular co-ordinates
    public void CyToRe(double x,double y,double z)
    {
       //Here x is Rho,y is Phi,z is z
       //Finding a which is x

       Z=x*Math.cos(DegToRad(y));

       //Finding b which is y

       Y=x*Math.sin(DegToRad(y));

       //Finding c which is z

       Z=z;

       System.out.println("Value of x:"+fmt.format(X));
       System.out.println("Value of y:"+fmt.format(Y));
       System.out.println("Value of z:"+fmt.format(Z));
    }

    //This method converts Cylinderical co-ordinates
    //to Spherical co-ordinates
    public void CyToSp(double x,double y,double z)
    {
       //Here x is Rho,y is Phi,z is z
       //Finding a which is r

       double d=x*x;
       double e=z*z;

       R=Math.sqrt(d+e);

       //Finding b which is Theta
       //and limiting it b/w 0 to 180 degree

       THETA=RadToDeg(Math.acos(z/R));
       while(THETA>180){
          THETA-=180;
       }

       //Finding c which is Phi

       PHI=y;
       System.out.println("Value of r:"+fmt.format(R));
       System.out.println("Value of Theta:"+fmt.format(THETA));
       System.out.println("Value of Phi:"+fmt.format(PHI));
    }

    //This method converts Spherical co-ordinates
    //to Rectangular co-ordinates

    public void SpToRe(double x,double y,double z)
    {
       //Here x is r,y is Theta,z is Phi
       //Finding a which is x

       X=x*Math.sin(DegToRad(y))*Math.cos(DegToRad(z));

       //Finding b which is y

       Y=x*Math.sin(DegToRad(y))*Math.sin(DegToRad(z));

       //Finding c which is z

       Z=x*Math.cos(DegToRad(y));

       System.out.println("Value of x:"+fmt.format(X));
       System.out.println("Value of y:"+fmt.format(Y));
       System.out.println("Value of z:"+fmt.format(Z));
    }

    //This method converts Spherical co-ordinates
    //to Cylinderical co-ordinates

    public void SpToCy(double x,double y,double z)
    {
       //Here x is r,y is Theta,z is Phi
       //Finding a which is Rho

       RHO=x*Math.sin(DegToRad(y));

       //Finding b which is Rho

       PHI=z;

       //Finding c which is z

       Z=x*Math.cos(DegToRad(y));

       System.out.println("Value of Rho:"+fmt.format(RHO));
       System.out.println("Value of Phi:"+fmt.format(PHI));
       System.out.println("Value of z:"+fmt.format(Z));
    }

    public double getX(){ return X; }
    public double getY(){ return Y; }
    public double getZ(){ return Z; }
    public double getR(){ return R; }
    public double getTHETA(){ return THETA; }
    public double getPHI(){ return PHI; }
    public double getRHO(){ return RHO; }

}

