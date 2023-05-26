#include<stdio.h>
void ODD_EVEN(int *A){
    for (int i = 0; i < 6; i++)
    {
        if (*(A+i)%2==0)
        {
            printf("Even\n");
        }
        else{
            printf("Odd\n");
        }
    }
    
}
int main(){
    
    int A[6]= {10,13,27,45,62,78};
    ODD_EVEN(A);

    return 0;
}