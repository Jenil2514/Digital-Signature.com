#include <iostream>
using namespace std;

class queue
{

public:
    int front, rear, size;
    int *arr;
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void Enque(int element)
    {
        if (rear == (size - 1))
        {
            cout << "Queue Is Full !" << endl;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
        if (front == -1)
        {
            front++;
        }
    }
    void Deque()
    {
        if (front >= rear)
        {
            front++;
            cout << "Queue is dead !" << endl;
        }
        else
            front++;
    }
    void peek()
    {
        cout << arr[front] << endl
             << arr[rear] << endl;
    }
};

int main()
{
    queue q(5);
    q.Enque(1);
    q.Enque(2);
    q.Enque(3);
    q.Enque(4);
    q.Enque(5);
    q.Deque();
    q.Deque();
    q.Deque();
    q.Deque();
    q.Deque();
    q.peek();
    return 0;
}