#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check(char str1[],int len){
    int n=len-1;
    // printf("%s -%d",str1,len);
    for(int i=0;i<=n;i++){
        printf("%d\n",i);
        if(str1[i]!=str1[n]){
            printf("in");
            return 0;
        }
        else{
            n--;
        }
    }
    return 1;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char str1[500];
    scanf("%s",str1);
    int i,len;
    len=strlen(str1);
    // printf("%d",len);
    i=check(str1,len);
    if(i==0){
        printf("NO");
    }
    else
        printf("YES");
    return 0;
}
