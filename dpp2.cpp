//Program 2
#include<iostream>
 #include<queue> 
 #include<string>
  #include<algorithm>
  using namespace std;
// int find_K_Largest(int arr[],int n,int k){
//     priority_queue<int,vector<int>,greater<int>> mh;
//     for(int i=0;i<n;i++){
//         mh.push(arr[i]);
//         if(mh.size()>k){
//             mh.pop();
//         }
//     }
//     return mh.top();
// }
// int main(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
        
//     }
//     cout<<find_K_Largest(arr,n,k)<<endl;
//     return 0;
// }


//Program3
// int fmp(int a[],int d[],int n){
//     sort(a,a+n);
//     sort(d,d+n);
//     int p=1;
//     int mp=1;
//     int i=1;
//     int j=0;
//     while(i<n && j<n){
//         if(a[i]<=d[j]){
//             p++;
//             i++;
//         }
//         else{
//             p--;
//             j++;
            
//         }
//         mp=max(mp,p);
//     }
//     return mp;
// }

// int main(){
//     int n;
//     cin>>n;
//     int a[n],d[n];
//     for(int i=0;i<n;i++)
//         cin>>a[i];
//     for(int i=0;i<n;i++)
//         cin>>d[i];
//     cout<<fmp(a,d,n)<<endl;
//     return 0;
// }


//Program1

// int medist(string s1,string s2, int n, int m){
//     int dp[n+1][m+1];
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             if(i==0){
//                 dp[i][j]=j;
//             }
//             else if(j==0){
//                 dp[i][j]=i;
//             }
//             else if(s1[i-1] == s2[j-1])
//                 dp[i][j]=dp[i-1][j-1];
//             else
//                 dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     int n,m;
//     string s1,s2;
//     cin >>n >>m >>s1 >>s2;
//     cout<<medist(s1,s2,n,m)<<endl;
// }