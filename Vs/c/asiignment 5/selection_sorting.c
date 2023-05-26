#include<stdio.h>



int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    //Input
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    // Sorting
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if(a[i]>a[j]){
                int temp;
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    
    

    return 0;
}