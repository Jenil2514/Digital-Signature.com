/*  
        a b   and or xor
        1 2   0   3  3
        1 3   1   3  2
        2 3   2   3  1
        here n=3 k=4
        here max of & = 2
        max of | = 3
        max of ^ = 3
        total length =n & thresold=k given find max of & | ^ which is less than k

        in below program n=5 and k=4 
    
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  int m1=0,m2=0,m3=0,i,c1=0,c2=0,c3=0;
  
  int ar[n];
  for(int i=0;i<n;i++){
      ar[i]=i+1;
  }  
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          c1=ar[i]&ar[j];
          c2=ar[i]|ar[j];
          c3=ar[i]^ar[j];
          if(c1>m1 && c1<k){
            m1=c1;
            }
           if(c2>m2 && c2<k){
               m2=c2;
           }
           if(c3>m3 && c3<k){
               m3=c3;
           } 
      }
      
  }
  printf("%d\n%d\n%d",m1,m2,m3);
}
int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
