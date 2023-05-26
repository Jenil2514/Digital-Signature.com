//Singly LINked LISt

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this-> data;
        if(this->next != NULL)
         {
            delete next;
            this->next = NULL;
         }
        

    }
};
void insertatfront(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertatlast(Node *head, int data)
{
    Node *temp = new Node(data);
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
}
void insertinmiddle(Node *&head, int position, int data2)
{
    Node *temp = new Node(data2);
    Node *temp2 = head;
    int cnt = 1;
    while (cnt<position-1)
    {
        temp2 = temp2->next;
        cnt++;
    }
    Node *temp3 = temp2->next;
    temp2->next = temp;
    temp->next = temp3;
}
void deletenode(Node *head,int position)
{
    if (position==1)
    {
        Node* temp = head;
        head = head->next;  
     // free memory
     temp->next=NULL;
     delete temp; 
    }
    
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while(cnt<position){
        prev = curr;
        curr = curr->next;cnt++;
    }
    
    prev -> next = curr ->next;
    //free memory
    curr->next=NULL;
    delete curr;
}
void traverse(Node *head, int position)
{
    Node *temp = head;
    int ctn = 1;
    while (ctn<position){
        temp = temp->next;
        ctn++;
    }

    cout << temp->data << endl;
}
void display(Node *head)
{
    // Node *temp = head;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    insertatfront(head, 20);
    // cout<<endl;
    // display(head);
    insertatfront(head, 30);
    // cout<<endl;
    // display(head);

    insertatlast(head, 40);
    // cout<<endl;
    // display(head);

    insertinmiddle(head,3,50);
    // cout<<endl;
    // display(head);

    deletenode(head,3);
    cout<<endl;
    display(head);

    cout<<endl;
    traverse(head,3);
    // display(head);

    return 0;
}
