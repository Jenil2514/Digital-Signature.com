#include<stdio.h>
#include<string.h>

int main(){

    char str[20];
    scanf("%s",&str);
    
        for (int j = 65; j < 123; j++)
        {
            for (int  i = 0; i < strlen(str); i++)
            {
                if (j==str[i])
                {
                    printf("%c ",str[i]);
                }
                
            }
            
            
        }
        
    
    

    return 0;
}