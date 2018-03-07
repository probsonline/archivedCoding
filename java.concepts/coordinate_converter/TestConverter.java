import java.io.*;
import java.text.DecimalFormat;

public class TestConverter
{
   public static void main(String[]args)throws IOException
   {
      BufferedReader stdin=new BufferedReader
         (new InputStreamReader(System.in));

      Converter D=new Converter();

      int a=0;
      double x=0.0,y=0.0,z=0.0;
      String k="c",l="r",m="s";

      while(a==0){
         System.out.println("Enter C for cylinderical coordinates OR");
         System.out.println("R for rectangular coordinates OR");
         System.out.println("S for spherical co-ordinate system");

         System.out.print("Input Co-ordinate system:");
         String i=stdin.readLine();

         System.out.println("Enter C for cylinderical,");
         System.out.println("R for rectangular or ");
         System.out.println("S for spherical co-ordinate system");

         System.out.print("Output Co-ordinate system:");
         String o=stdin.readLine();
         System.out.println("Enter values of input");

         if(i.equalsIgnoreCase(k))
         {
            System.out.print("Value of Rho:");
            x=Double.parseDouble(stdin.readLine());

            System.out.print("Value of Phi:");
            y=Double.parseDouble(stdin.readLine());

            System.out.print("Value of z:");
            z=Double.parseDouble(stdin.readLine());

            if(o.equalsIgnoreCase(l))
            {
               D.CyToRe(x,y,z);
            }

            if(o.equalsIgnoreCase(m))
            {
               D.CyToSp(x,y,z);
            }
         }

         if(i.equalsIgnoreCase(l))
         {
            System.out.print("Value of x:");
            x=Double.parseDouble(stdin.readLine());

            System.out.print("Value of y:");
            y=Double.parseDouble(stdin.readLine());

            System.out.print("Value of z:");
            z=Double.parseDouble(stdin.readLine());

            if(o.equalsIgnoreCase(k))
            {
               D.ReToCy(x,y,z);
            }

            if(o.equalsIgnoreCase(m))
            {
               D.ReToSp(x,y,z);
            }
         }

         if(i.equalsIgnoreCase(m))
         {
            System.out.print("Value of r:");
            x=Double.parseDouble(stdin.readLine());

            System.out.print("Value of Theta:");
            y=Double.parseDouble(stdin.readLine());

            System.out.print("Value of Phi:");
            z=Double.parseDouble(stdin.readLine());

            if(o.equalsIgnoreCase(l))
            {
               D.SpToRe(x,y,z);
            }

            if(o.equalsIgnoreCase(k))
            {
               D.SpToCy(x,y,z);
            }
         }

         System.out.print("If you want to do more conversion Enter 0 oterwise Esc Key.");

         a=Integer.parseInt(stdin.readLine());
      }
   }
}

class Converter
{
   double a,b,c;

   public Converter()
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







