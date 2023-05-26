#include<stdio.h>
#include<stdlib.h>

int main()

{
    int a=0,b=0,num;
    int pizza=240,burger=70;
    char ch;

    for(;;){
        fflush(stdin);
        printf("which  item : ");
        // getchar();
        scanf("%c",&ch);
        if(ch=='e'){
            goto end;
        }
        printf("Enter number of pizza or burger : ");
        scanf("%d",&num);
        

        switch(ch){
            case 'p':
                a=a + num*pizza;
                // s=a;  
                printf("amount : %d\n",a);    
                break;
            case 'b':
                b=b + num*burger;
                // f=b;
                printf("amount : %d\n",b);    
                printf("Do you want to exit :");
                getchar();
                scanf("%c",&ch);
                if(ch=='y')
                   goto sum;
                break;
            case 'e':
            end:
                
                goto sum;
        }
    }

sum:
    printf("Total amount is : %d",a+b);
    

    return 0;
}