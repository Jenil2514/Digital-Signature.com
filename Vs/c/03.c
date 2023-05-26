#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,a,b;
    char c;
   
    
    while (1)
    {
    printf("Enter a b ");
    scanf("%d %d",&a,&b);
    getchar();
    printf("enter choice :");
    scanf("%c",c);
        switch(c){
            case 'p':
                printf("%d",a+b);
                break;
            case 'm': 
                printf("%d",a-b);
                break;
            case 'e':
                       exit(0);
                break;
            }
        }
        return 0;

    }
    
    