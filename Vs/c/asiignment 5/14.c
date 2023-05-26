#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char name[50];
    scanf("%s",name);
    int len=strlen(name);
    
    for(int i=0;i<len;i++){
        int count=0;
        
        for(char ch='A';ch<91;ch++){
            if(name[i]==ch){
                count++;
            }
        }
        for(int j=0;j<len;j++){
            for(int k=0;k<j;k++){
                if(name[j]==name[k]){
                    continue;
                }
                else
                    if(i<len-1){
                        printf("%c:%d,",name[j],count);
                    }
                else
                    printf("%c:%d",name[j],count);
            }
        }
    }
    return 0;
}
