#include<stdio.h>

int main(){
    int i,j,n=5,k=1;
    for(i=1;i<=n;i++){
        for(int space=0;space<(n-i);space++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d ",k);
        }
        
        printf("\n");
    }
    return 0;
}