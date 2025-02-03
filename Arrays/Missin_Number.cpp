#include<iostream>
using namespace std;
int main(){
    // int arr[]={1,3,4,5};
    int size;
    int arr[100];
    cin>>size;
    size++;
    int sum =size*(size+1)/2;
    cout<<"Sum of the N natural Numbers are :"<<sum<<endl;
    int sum1=0;
    for(int i=0;i<size-1;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size-1;i++){
        sum1+=arr[i];
    }
    cout<<"Missing Number is"<<sum-sum1;
}