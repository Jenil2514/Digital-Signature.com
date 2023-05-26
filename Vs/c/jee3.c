#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,a,b;
    char c;
   
    
    while (1)
    {
    
    
    printf("enter choice :");
    scanf("%c",&c);
        switch(c){
            case 'p':
            printf("Enter a b ");
        scanf("%d %d",&a,&b);
                printf("%d",a+b);
                break;
            case 'm': 
            printf("Enter a b ");
        scanf("%d %d",&a,&b);
                printf("%d",a-b);
                break;
            case 'e':
                       exit(0);
                break;
            }
        }
        return 0;

    }
    
    