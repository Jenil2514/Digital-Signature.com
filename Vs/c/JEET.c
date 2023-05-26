#include<stdio.h>

int main()
{

    int r,g,b;

    printf("r g b values : ");
    scanf("%d %d %d",&r,&g,&b);  

    if(r>0 && g>0 && b>0){

        float s;
        
        float i=(float)r/255;
        float u=(float)g/255;
        float o=(float)b/255;
        if(i>u && i>o){
            s=i;
        }
        else if(u>i && u>o){
            s=u;
        }
        else if(o>i && o>u){
            s=o;
        }    

        float w = s;      
        float c = ((w-i)/w);
        float m = ((w-u)/w);
        float y = ((w-o)/w);
        float k = 1-w; 

        if(w>0 && w<=1){
            printf("c-m-y-k : %.2f %.2f %.2f %.2f",c,m,y,k);
        }
    }

    else if(r==0 && b==0 && g==0){
        printf("c-m-y-k : 0-0-0-1");
    }


    return 0;
}