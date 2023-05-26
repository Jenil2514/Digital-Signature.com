#include<iostream>
using namespace std;
int findUnique(int *arr, int size)
{
    //Write your code here
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            cout<<arr[i];
        }
    }
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    findUnique(arr,n);
    return 0;
}