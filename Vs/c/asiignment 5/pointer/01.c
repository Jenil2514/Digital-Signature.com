#include <stdio.h>
#include <stdlib.h>

int main()
{

    // char b[7]="C Quiz";
    // char *c="Hello";
    // int a[10]={1,2,3,4,5};
    // printf("%d",sizeof(a));
    // char *p=NULL;

    // p=b;
    // p[2]='A';
    // printf("%s",p);
    // c[2]='B';
    // printf("%s",c);

    char arr[5] = {'e', 'x', 'c', 'e', '\0'};
    char *ptr;
    ptr = arr;
    printf("%s\n", arr);
    *ptr='p';
    // printf("%c", *(arr+=3));

    // int a[10]={5,13,6,7,8,9,2};
    // int *p;
    // p=a;
    // printf("%d ",*++p+2);

    // printf("%d ",*p);
    // printf("%d",*(p--+3)+10);

    // int n;
    // n=5;

    // int *arr=(int *)malloc(n*sizeof(int));
    // int *ptr=(int *)malloc(10*sizeof(int));
    // for (int i = 0; i < 6; i++)
    // {
    //     scanf("%d",&*(arr+i));
    // }
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("%d",*(arr+i));
    // }

    return 0;
}