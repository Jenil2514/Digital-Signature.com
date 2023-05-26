import java.util.*;
class Rectangle{
    int area,l,w,p;
    
    
    void rec(){
        
        area=this.l*this.w;
        System.out.println("Area IS "+area);
        p=2*(this.l+this.w);
        System.out.println("Perimeter "+p);
    }
}
class square{
    int area,l,pe;
    void sq(){
        area=this.l*this.l;
        System.out.println("Area Is "+area);
        pe=4*this.l;
        System.out.println("Perimeter "+pe);

    }
}
public class que2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
     
        Rectangle r=new Rectangle();
        System.out.println("Enter Length of Rectangle : " );
        r.l=sc.nextInt();
        System.out.println("Enter Width Of Rectangle : ");
        r.w=sc.nextInt();
        r.rec();
        square s=new square();
        System.out.println("Enter Width Of Squre : ");
        s.l=sc.nextInt();
        s.sq();
        
    }
}
