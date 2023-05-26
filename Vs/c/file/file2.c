#include<stdio.h>
typedef struct fil
{
    int num1,num2;
}fi;

int main(){

    FILE *f;
    fi f2;
    // int num1,num2;
    // f=fopen("txt2.txt","w");
    // printf("Enter 2 Num : ");
    // scanf("%d %d",&num1,&num2);
    // fprintf(f,"%d %d",num1,num2);
    // fclose(f);   
    char S[20];
    f=fopen("txt2.txt","r");
    
    while (fscanf(f,"%s",S)!=EOF)
    {
        f2.num1=(int)S;
        
    }

    fclose(f);
    printf("%d %d",f2.num1,f2.num2);
    
    
    return 0;
}