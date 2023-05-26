#include <stdio.h>

int main()
{
    int r, c, n,i,k;
    printf("enter numbr");
    scanf("%d", &n);
    for (r=n;r>0;r--){
        for(int space=0;space<n-r;space++){
                printf("%d ",n-space);
        }
        for(c=1;c<=(2*r-1);c++){
            printf("%d ",r);
           
        }
        for(int space=0;space<n-r;space++){
                printf("%d ",r+space+1);
        }
       printf("\n");

    }
    for(r=2;r<=n;r++){
        for(int space=0;space<(n-r);space++){
            printf("%d ",n-space);
        }
        for(c=0;c<2*r-1;c++){
            printf("%d ",r);
        }
         for(int space=0;space<(n-r);space++){
            printf("%d ",r+1+space);
        }
        printf("\n");
    }
        return 0;
}