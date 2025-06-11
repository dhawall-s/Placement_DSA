#include <bits/stdc++.h>
using namespace std;
//pass by value
int dosome(int num){
        cout<<num<<endl;
        num+=5;
        cout<<num<<endl;
        num+=5;
        cout<<num<<endl;
        return 0;
    }

//pass by reference
int dosome2(int &num2){
    cout<<num2<<endl;
        num2+=5;
        cout<<num2<<endl;
        num2+=5;
        cout<<num2<<endl;
        return 0;
}    
     

 int main() {
    // int x, y;
    // int z = 20;
    // cout << z << endl;

    // long long z1 = 1929302802830;
    // cout << z1 << endl;

    // cin >> x >> y;
    // cout << "value of x is " << x << " and y is: " << y << endl;

    // double vari=3.09090;
    // cout<<vari<<endl;

    // float fl=0.393983;
    // cout<<fl;

    // string str;
    // getline(cin,str);
    // cout<<str;

    // char ch;
    // cin>>ch;
    // cout<<ch;


    // int age;
    // cin>>age;
    // if(age>=18){
    //     cout<<"welcome";
    // }
    // else{
    //     cout<<"go outside";
    // }

//call by value
       int num=5;
        dosome(num);
        cout<<num;
        cout<<endl;

        int num2=5;
        dosome2(num2);
        cout<<num2;


   return 0;
 }
