#include<stdio.h>

void swap(int* a1, int* b1){
    int temp=0;
    temp=*a1;
    *a1=*b1;
    *b1=temp;
}
int main(){
    int a,b;
    a=5;
    b=3;
    swap(&a,&b);
    printf("%d %d",a,b);

    return 0;
}