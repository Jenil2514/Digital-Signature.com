#include<stdio.h>

int main(){
    int pizza,burger,sum=0,num;
    char choice,choice2;
    
    
    
    for(;;)
    {
    
   start:
    fflush(stdin);
     printf("Enter Your choice : ");
    scanf("%c",&choice);
        switch (choice)
        {
        case 'p':
                printf("Enter Amount : \n");
                scanf("%d",&num);
                sum= sum + num*100;
                printf("Want to add another : Yes= Y|y No: N|n \n");
                getchar();
                scanf("%c",&choice2);
                if(choice2=='y' || choice2=='Y'){
                    goto start;
                }
                else if(choice2=='N' || choice2=='n'){
                    goto end;
                }
            break;
        case 'b':
            printf("enter amount : \n");
            scanf("%d",&num);
            sum=sum+ num*80;
            printf("Want to add another : Yes= Y|y No: N|n\n ");
            getchar();
                scanf("%c",&choice2);
                if(choice2=='y' || choice2=='Y'){
                    goto start;
                }
                else if(choice2=='N' || choice2=='n'){
                    goto end;
                }

        
        }
        
    }
    end:
    printf("%d",sum);
    return 0;
}