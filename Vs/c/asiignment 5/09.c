#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n],freq[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        
    }
    for (int i = 0; i < 10; i++)
    {
        freq[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i]==j)
            {
                freq[j]++;
            }
            
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d : %d\n",i,freq[i]);
    }
    
    
    

    return 0;
}