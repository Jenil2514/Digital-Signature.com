#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int n,r,a=0;
    scanf("%ld",&n);
    for(;n!=0;){
        r=n%10;
        printf("%ld",r);
        n=n/10;
       
    }
    //  printf("%ld",a);
    
    return 0;
}
