
// Circular LInked List

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
    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void InsertNode(Node *&tail, int element, int data)
{

    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletenode(Node *&tail, int value)
{

    if (tail == NULL)
    {
        cout << "Empty LIst ! ";
    }
    else
    {
        Node *perv = tail;
        Node *curr = perv->next;
        while (curr->data != value)
        {
            perv = curr;
            curr = curr->next;
        }

        perv ->next = curr->next;
        curr->next = NULL;
        if (tail == curr)
        {
            tail = perv;
        }

        delete curr;
    }
}

void display(Node *tail)
{

    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}
int main()
{
    Node *tail = NULL;
    InsertNode(tail, 5, 10);
    InsertNode(tail, 10, 20);
    InsertNode(tail, 20, 30);
    InsertNode(tail, 30, 40);
    InsertNode(tail, 40, 50);
    // display(tail);

    // insert between node

    InsertNode(tail, 20, 25);
    cout << endl;
    display(tail);
    cout << endl;

    deletenode(tail, 30);
    display(tail);

    return 0;
}