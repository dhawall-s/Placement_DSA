// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// struct Meeting{
//     int start,end,pos;
// };

// bool compare(Meeting m1, Meeting m2){
//     return m1.end<m2.end;
// }

// int maxM(int n,vector<int>&start,vector<int>& end){
 
//     vector<Meeting> meets(n);
//     for(int i=0;i<n;i++){
      
//         meets[i]={start[i],end[i],i+1};
//     }
//     sort(meets.begin(),meets.end(),compare);
    
//     int count=1;
//     int last_end=meets[0].end;
   
    
//     for(int i=1;i<n;i++){
//         if(meets[i].start > last_end){
//             count++;
//             last_end=meets[i].end;
//         }
//     }
//     return count;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> start(n),end(n);
//     for(int i=0;i<n;i++)
//     cin>>start[i];
//     for(int j=0;j<n;j++)
//     cin>>end[j];
//     cout<<maxM(n,start,end) <<endl;
//     return 0;
    
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// void r(vector<int>& t) {
//     int n = t.size();
//     int l = -1;
//     for (int i = 0; i < n; i++) {
//         if (t[i] != -1) {
//             l = t[i];
//         } else if (l != -1) {
//             t[i] = l;
//         }
//     }
//     l = -1;
//     for (int i = n - 1; i >= 0; i--) {
//         if (t[i] != -1) {
//             l = t[i];
//         } else {
//             if (l != -1) {
//                 int p = -1;
//                 for (int j = i - 1; j >= 0; j--) {
//                     if (t[j] != -1) {
//                         p = t[j];
//                         break;
//                     }
//                 }
//                 if (p != -1) {
//                     t[i] = (p + l) / 2;
//                 }
//             }
//         }
//     }
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<int> t(n);
//     for (int i = 0; i < n; i++) {
//         cin >> t[i];
//     }
//     r(t);
//     for (int x : t) {
//         cout << x << " ";
//     }
//     cout << endl;
//     return 0;
// }