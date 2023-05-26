#include<stdio.h>

int main(){
    int Positive=0,Negative=0;
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i]>0)
        {
            Positive++;
        }
        else if (a[i]<0)
        {
            Negative++;
        } 
    }
    
    printf("%d %d",Positive,Negative);
    

    return 0;
}