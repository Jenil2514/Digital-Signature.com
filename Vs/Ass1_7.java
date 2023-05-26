import java.util.*;
class Ass1_7{
    public static void main(String[] args) {
        Scanner s1=new Scanner(System.in);
       int no,marks[]=new int[3];
       System.out.println("Enter ID NO: ");
       no=s1.nextInt();
       System.out.println("Enter MArks oF THree Subjects : ");
       for(int i=0;i<marks.length;i++){
        System.out.println("Enter Marks of Sub "+i+": ");
        marks[i]=s1.nextInt();
       }
       System.out.println("ID NO: ");
       System.out.println(no);
       System.out.println("Marks OF Subjects : ");
       for(int i=0;i<marks.length;i++){
        System.out.println(marks[i]);
       }

       

    }
}