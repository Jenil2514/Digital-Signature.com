// Exercise Create a class complex to represent complex numbers. Each number
// has a real part and an imaginary part. The class has two member functions
// add() and multiply() which perform the task of adding and multiplying two
// complex numbers respectively. Write a C++ code to take two complex numbers
// form a user and perform their addition and subtraction and display it in the
// format of a complex number. Decide appropriate return types and argument
// data types for your functions. You can create another function to display your
// output if you need. Name your code as Lab1_3_yourrollno.cpp
// By the end of this lab hopefully you should be able to write basic C++ codes
// involving classes, class objects , member functions and normal functions etc.
#include<iostream>
using namespace std;
class complex{
    public:
        int real,img;
        void add(int num1,int num2, int num3, int num4){
            int sum1=0,sum2=0;
            sum1 = num1+num2;
            sum2 = num3+num4;
            if (sum2<0)
            {
                cout<<"Sum : "<<sum1<<sum2<<"i"<<endl;
            }
            
            else 
                cout<<"Sum : "<<sum1<<"+"<<sum2<<"i"<<endl;
        }
        void multiply(int num1,int num2, int num3, int num4){
            int mul1=1,mul2=1;
            mul1 = num1*num2;
            mul2 = num3*num4;
            if (mul2<0)
            {
                cout<<"Multiply : "<<mul1<<mul2<<"i";
                
            }
            else
                cout<<"Multiply : "<<mul1<<"+"<<mul2<<"i";
        }
};


int main(){
    complex c1,c2,c3;
    cout<<"Enter Complex num 1 : ";
    cin>>c1.real>>c1.img;
    cout<<"Enter Complex num 2 : ";
    cin>>c2.real>>c2.img;
    c3.add(c1.real,c2.real,c1.img,c2.img);
    c3.multiply(c1.real,c2.real,c1.img,c2.img);
    
    return 0;
}
