#include<iostream>
using namespace std;
void patt1(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void patt2(){
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    patt1();
    patt2();
    return 0;
}