package Java;

public class method_overloding {
    static void method1(int i,int j){
        int sum=i+j;
        System.out.println(sum);
    }
    static void method2(float a,float b){
        float add=a+b;
        System.out.println(add);
    }
    public static void main(String[] args) {
        method1(10, 20);
        method2(10.5f, 20.5f);
       
        

    }
}
