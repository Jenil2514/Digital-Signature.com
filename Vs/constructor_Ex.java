public class constructor_Ex {
    int x;
  
    public constructor_Ex(int y) {
      x = y;
    }
  
    public static void main(String[] args) {
      constructor_Ex myObj = new constructor_Ex(5);
      System.out.println(myObj.x);
    }
  }
  