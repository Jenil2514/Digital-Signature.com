#include<iostream>
using namespace std;


int swapp(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    // int num = 5;
    // int* p1=&num;
    // int* p2=p1;
    // cout<< p1 <<" - "<<p2<<endl;
    // cout<< *p1 <<" - "<<*p2<<endl;
    int x=1,y=2;
    swapp(x,y);
    cout<<x<<" "<<y;


    return 0;
}