#include<stdio.h>

int main(){
    int n=3,sum=0,diff=0;
    int a[n][n],b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("\n----------------------------\nArray 2\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }
    // printf("\n-----------------------Sum----------------------\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         sum=a[i][j]+b[i][j];
    //         printf("%d ",sum);
    //     }
    //     printf("\n");
        
    // }
    // printf("\n-----------------------Diff----------------------\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         diff=a[i][j]-b[i][j];
    //         printf("%d ",diff);
    //     }
    //     printf("\n");
        
    // }

    // // A^T
    // printf("\n----------------------------A^t---------------------------\n1=");
    // for (int  i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ",a[j][i]);
    //     }
    //     printf("\n");
        
    // }
    
    

    return 0;
}