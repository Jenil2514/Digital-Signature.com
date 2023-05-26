#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void modify(char *str,char *word){
    int i,j;
    int ttl=0;
    int c,w;
    w=strlen(str);
    c=strlen(word);
   for(i=0;i<w;i++){
       int temp=i;
       for(j=0;j<c;j++){
           if(str[i]==word[j]){
               i++;
           }
       }
       ttl=i-temp;
       if(ttl==c){
           i=temp;
           for(j=i;j<c;j++){
               str[j]=str[j+c];
           }
           
           // str[j]='\0';
           w=w-c;
       }
   }
    printf("%s",str);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char str[1000],word[100];
    fgets(str,1000,stdin);
    fgets(word,100,stdin);
    modify(str,word);
    
    return 0;
}
