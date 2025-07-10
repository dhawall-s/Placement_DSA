#include<iostream>
using namespace std;
int cs(int n){
    if(n<=1)
        return 1;
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
        
    }
    return arr[n];
}
int main(){
    int n=5;
    cout<<cs(n);
}