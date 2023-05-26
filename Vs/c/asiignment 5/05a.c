#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void witharray(long int num){
    int a[num],rev[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < num; i++)
    {
        rev[i]=a[num-i-1];
    }
    printf("Using another array: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",rev[i]);
    }
}
void withoutarray(long int num){
    int a[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nWithout using another array: ");
    for (int i = num-1; i >= 0; i--)
    {
        printf("%d ",a[i]);
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long int num;
    scanf("%ld",&num);
    witharray(num);
    withoutarray(num);
    return 0;
}
