#include<stdio.h>
#include<stdlib.h>
#define unix 1.0

struct Node
{
    int id;
    struct Node *next;
};

int main(){

    #ifdef unix
         printf("HI IN");
         // hello
    
    #else
            // printf("not");
    #endif
   

    // struct Node *ptr;
    // struct Node *head=(struct Node*)malloc(sizeof(struct Node));;
    
    // head->id=1;
    // head->next=NULL;
    
    // ptr=(struct Node*)malloc(sizeof(struct Node));
    // ptr->id=2;
    // ptr->next=NULL;
    // head->next=ptr;

    // // struct Node *ptr2;
    // ptr=(struct Node*)malloc(sizeof(struct Node));
    // ptr->id=3;
    // ptr->next=NULL;
    // head->next->next=ptr;
    // // ptr->next=ptr2;

    // int count=0;
    // struct Node *cou=NULL;
    // cou=head;
    // while (cou!=NULL)
    // {
    //     count++;
    //     cou=cou->next;
    // }
    // printf("%d",count);

    return 0;
}