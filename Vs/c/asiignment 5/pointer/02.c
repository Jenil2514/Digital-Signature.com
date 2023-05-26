#include<stdio.h>

int main(){

    int a[2][4]={{1,2,3,4},{5,6,7,8}};
    int *p;
    p=*(a+1)-2;
    printf("%d\n",*p);
    printf("%d",*(*(a+1)-2));

    return 0;
}