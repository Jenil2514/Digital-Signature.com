#include<stdio.h>
void fun1(int* ptr){
    for (int i = 0; i < 5; i++)
    {
        printf("%d",*ptr[i]);
    }
    
}
int main(){
    int a[]={1,2,3,45,6};
    fun1(a);
    return 0;
}