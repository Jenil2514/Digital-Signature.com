#include<stdio.h>

int main(){
    
    int a[20]={1, 5, 4, 8, 9, 2, 0, 5, 1, 7, 8, 0, 1, 8, 9, 5, 3, 9, 4, 2};
    int num,found=0;
    scanf("%d",&num);
    for (int i = 0; i < 20; i++)
    {
        if (num==a[i])
        {
            printf("%d",i);
            found=1;
            break;
        }
        
    }
    if(found==0){
        printf("-1");
    }
    

    return 0;
}