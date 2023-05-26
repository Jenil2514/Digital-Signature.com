#include<stdio.h>
int main()
{
  char a[60]; 
  int i=0;
  printf("Enter the string\n");
  gets(a);
//   puts(a);
  while(a[i]!='\0')
  {
    // printf("%s",a[i]);
     if(a[i]==' ')
     {		
       printf("\n");
     }
     else{
        printf("%c",a[i]);
     }
     i++;  
  }
//   printf("Number of blank spaces in a string is %d",count);
}