#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num1,num2,choice;
    float quotient;
    quotient=num1/num2;
    scanf("%d",&choice);
    scanf("%d %d",&num1,&num2);
    switch(choice){
        case 1:
            printf("%d",(num1+num2));
            break;
        case 2:
            printf("%d",(num1-num2));
            break;
        case 3:
            printf("%d",(num1*num2));
            break;
        case 4:
            
            quotient=num1/num2;
            printf("%f",quotient);
            break;
    }
    
    return 0;
}
