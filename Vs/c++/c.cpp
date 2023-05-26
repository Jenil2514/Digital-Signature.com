#include<iostream>
using namespace std;

class way{
    private:
    int meter;
    public:
    way():meter(0){
        cout<<meter;
    }
};
int main(){
    way w;
    
    return 0;
}