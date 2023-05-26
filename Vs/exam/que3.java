import java.util.*;

public class que3 {
    public static void main(String[] args) {
        int unit[]=new int[5];
        double bill[]=new double[5];
        String name[]=new String[5];
        Scanner sc= new Scanner(System.in);
        for(int i=1;i<=5;i++){
        System.out.println("Enter NAme ");
        name[i]=sc.nextLine();
        System.out.println("Enter UNites for 5 years");
        unit[i]=sc.nextInt();
        if(unit[i]<=100)
        {
            bill[i]=unit[i]*0.60+50;
        }
        else if(unit[i]<=200)
        {
            bill[i]=(unit[i]-100)*0.80+60+50;
         }
         else if(unit[i]<=300){
            bill[i]=(unit[i]-200)*0.90+140+50;
         }
         if(bill[i]>300){
            bill[i]=bill[i]+(bill[i]*.15);
         }
        }
        for(int i=1;i<=5;i++){
            System.out.println("Bill For"+name[i]+bill[i]);
        }


    }
}
