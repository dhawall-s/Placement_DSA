#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,-1,2,-2,3};
     int arr2[5];
     int store[5];
        for(int i=0;i<5;i++){
            if(arr[i]>=1){
                store[i]=arr[i];
            }
            else{
                arr2[i]=arr[i];
            }
        }
        return store[5]+arr2[5];
}