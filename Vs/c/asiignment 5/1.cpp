#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int arr[100];
    int i=0;
    while(cin>>arr[i]){
        i++;
    }
    for(int j=0;j<i;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}
