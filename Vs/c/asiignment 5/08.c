#include<stdio.h>
int num;
int Get_data(){
    scanf("%d",&num);
    return num;
}

void EVEN_ODD(){
    int num;
    num = Get_data();
    if (num%2==0)
    {
        printf("Even");
    }
    else
        printf("Odd");
    
}

int main(){

    
    EVEN_ODD(num);

    return 0;
}