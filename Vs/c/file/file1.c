#include<stdio.h>
#include<stdlib.h>
typedef struct com
{
    int id,age;
    char name[20];
    char lname[20];
    char gen;
}st;

int fun(st *ptr,int max){
    FILE *f;
    f= fopen("Txt.txt","r");
    // char ch;
    for (int i = 0; i < max; i++)
    {
        fscanf(f,"%d",&ptr->id);
        fscanf(f,"%d",&ptr->age);
        fscanf(f,"%c",&ptr->gen);
        fscanf(f,"%s",ptr->name);
        fscanf(f,"%s",ptr->lname);

    }
    
    // for (int i = 0; i < max; i++)
    // {
    //     printf("id : ");
    //     scanf("%d",ptr->id);
    //     printf("Age : ");
    //     scanf("%d",ptr->age);
    //     printf("GEn : ");
    //     scanf("%c",ptr->gen);
    //     printf("NAme : ");
    //     scanf("%s",ptr->name);
    //     printf("lname : ");
    //     scanf("%s",ptr->lname);

    // }

    for (int i = 0; i < max; i++)
    {
        printf("id : %d\n",ptr->id);
        // scanf("%d",ptr->id);
        printf("Age : %d\n",ptr->age);
        // scanf("%d",ptr->age);
        printf("GEn : %c\n",ptr->gen);
        // scanf("%c",ptr->gen);
        printf("NAme : %s\n",ptr->name);
        // scanf("%s",ptr->name);
        printf("lname : %s\n",ptr->lname);
        // scanf("%s",ptr->lname);

    }
    fclose(f);
    
}


int main(){

    // st s
    // char str[10000];
    

    int max;
    scanf("%d",&max);
    st *ptr=(st *)malloc(max*sizeof(st));
    fun(ptr,max);
    free(ptr);
    // f=fopen("Txt.txt","w");
    // printf("Enter Text : \n");
    // fgets(str,100,stdin);
    // fputs(str,f);
    // fclose(f);
    // f=fopen("txt.txt","r");
    // char ch;

    // while ((ch=getc(f))!=EOF)
    // {
    //     printf("%c",ch);
    // }
    // fclose(f);
    
    



    return 0;
}