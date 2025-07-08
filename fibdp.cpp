// #include<iostream>
// #include<vector>
// using namespace std;

// int fib(int n, vector<int>&dp){
//     if(n==0 || n==1)
//         return n;
//     if (dp[n]!=-1)
//         return dp[n];
//     else    
//         return dp[n]=fib(n-1,dp)+fib(n-2,dp);
// }

// int main(){
//     int n;
//     vector<int>dp(n+1,-1);
//     cin>>n;
//     cout<<fib(n,dp);
// }

// #include<iostream>
// using namespace std;

// int fib(int n){
//     int a[100];
//     a[0]={0};
//     a[1]={1};
//     for(int i=2;i<n;i++){
//         a[i]=a[i-1]+a[i-2];
//     }
//     return a[n];
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<fib(n);
    
// }