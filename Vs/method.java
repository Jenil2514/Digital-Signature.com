public class method {
    // Public Method It can't be called by Object
    public void mycar() {
        System.out.println("This is my car");
        
    }
    // Static Method It can called withought creating Object
    static void car(){
        System.out.println("My car 2");
    }
    public static void main(String[] args) {
        car();
      //mycar(); This will Give Error
        method m=new method();
        m.mycar();
      

        
    }
}
