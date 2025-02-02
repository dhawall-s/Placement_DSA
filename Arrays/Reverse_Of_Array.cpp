#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int start=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    int end=size-1;
    cout<<"Original Array";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    cout<<endl;
    cout<<"Reverse of an Array";
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
}