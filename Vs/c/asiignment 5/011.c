#include<stdio.h>
void swapV(int a1, int b1){
    int temp=0;
    temp=a1;
    a1=b1;
    b1=temp;
    
}
void swapR(int* a1, int* b1){
    int temp=0;
    temp=*a1;
    *a1=*b1;
    *b1=temp;
}
int main(){
    int a,b;
    a=5;
    b=3;
    printf("%d %d\n",a,b);
    swapV(a,b);
    printf("%d %d\n",a,b);
    swapR(&a,&b);
    printf("%d %d\n",a,b);

    return 0;
}