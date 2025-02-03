#include<iostream>
#include<vector>
using namespace std;
void valueEqualToIndex(vector<int>& arr) {
    bool found = false;  
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == i + 1) {
            cout << i + 1 << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "-1";  
    }
    cout << endl;
}

int main(){

}