#include <iostream>
using namespace std;

class stack
{

public:
    int *arr;
    int size, top;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow ! " << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
            cout << "Stack underflow ! " << endl;
    }
    void peek()
    {
        if (top >= 0)
        {
            cout << arr[top];
        }
        else
            cout << "Stack is empty ! " << endl;
    }
    void Isempty(){
        if(top==-1){
            cout<<"Stack Empty !";
        }
        else
            cout<<"Not Empty ";
    }
};

int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(89);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // st.peek();
    return 0;
}