import java.util.*;
class que1{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int choice ,n1,m=0,f=0,i,r,total=0,t,a,b,ans=0;
        System.out.println("Enter Your Choice !");
        System.out.println("1 for Checking Odd and Even \n 2 for Primmary NUmber \n 3 For Palinrdrome NUmber \n 4 for Armstrong Number ");

        choice=sc.nextInt();
        System.out.println("Enter YOur NUmber!");
        n1=sc.nextInt();
       
        switch(choice)
        {
            case 1:
                if(n1%2==0){
                    System.out.println("Number Is Even!");
                }
                else if(n1%2!=0){
                    System.out.println("NUmber IS Odd!");
                }
                else{
                    System.out.println("Number IS Zero!");
                }
                break;
            case 2:
                m=n1/2;
                if(n1==0||n1==1){  
                    System.out.println(n1+" is not prime number");      
                   }else{  
                    for(i=2;i<=m;i++){      
                     if(n1%i==0){      
                      System.out.println(n1+" is not prime number");      
                      f=1;      
                      break;      
                     }      
                    }      
                    if(f==0)  { System.out.println(n1+" is prime number"); }  
                   }
                 
                break;
            case 3:
                t=n1;
                while(n1>0){
                    r=(n1%10);
                    total=(total*10)+r;
                    n1=n1/10;
                }
                if(t==total){
                    System.out.println(n1+"IS palinedrome NUmber");
                }
                else{
                    System.out.println(n1+"IS NOt PAlinedrome NUmber");
                }
                break;
            case 4:
                a=n1;
                while(a!=0)    {
                    b=a%10;
                    ans+=Math.pow(b,3);
                    a/=10;
                }
                if(ans==n1){
                    System.out.println(n1+"Is Armstrong number");
                }
                else{
                    System.out.println(n1+"IS not Armstrong number.");
                }
        }
    }
}