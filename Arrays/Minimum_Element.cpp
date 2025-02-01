#include<iostream>
#include<climits> //for using INT_MAX
using namespace std;
int main(){
    int ans=INT_MAX;
    int arr[5]={4,6,11,2,8};
    for(int i=0;i<5;i++){

       // if(arr[i]>ans)
       if(ans>arr[i])
                ans=arr[i];  
     // return ans;
    }
    cout<<"Minimum Number Is"<<ans;
    return 0;
}