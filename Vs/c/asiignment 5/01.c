#include<stdio.h>

int main(){
    int max=0,min;
    int a[20];
    for(int i=0;i<20;i++){
        printf("ent %d - ",i+1);
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
        
    }
    min=max;
    for (int i = 0; i < 20; i++)
    {
        
        if(min>a[i])
        {
            
            min=a[i];
        }
    }
    printf("%d %d",max,min);
    
    

    return 0;
}