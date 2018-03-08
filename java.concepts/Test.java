class A{int x = 5;}
class B extends A{int x = 6;}
class Test{
   public static void main(String[]args){
      A a = new B();
      System.out.println(a.x);
   }
}


