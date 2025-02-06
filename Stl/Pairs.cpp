#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
void print(){
    cout<<"Raj";
}
int sum(int a, int b){
    return a+b;
}
void explainPair(){
     pair<int,int>p={1,3};
     cout<<p.first<<" "<<p.second;
     cout<<endl;
     pair<int, pair<int,int>> p1={1,{3,4}};
     cout<<p1.first<<" "<<endl<<p1.second.second<<endl<<p1.second.first;
     pair<int,int>arr[]={{1,2},{4,5},{7,8}};
     cout<<endl;
     cout<<arr[1].second;
}

int main(){
    // int a;
    // cin>>a;
    // cout<<a;
    // int s=sum(5,5);
    // cout<<s;
    explainPair();
    return 0;

}