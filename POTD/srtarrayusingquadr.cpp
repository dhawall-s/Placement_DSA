#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        
        auto f = [&](int x) -> int {
            return A * x * x + B * x + C;
        };
        
        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;
        while (left <= right) {
            int leftVal = f(arr[left]);
            int rightVal = f(arr[right]);
            
            if (A >= 0) {
                if (leftVal > rightVal) {
                    result[index--] = leftVal;
                    left++;
                } else {
                    result[index--] = rightVal;
                    right--;
                }
            } else {
                if (leftVal < rightVal) {
                    result[index++] = leftVal;
                    left++;
                } else {
                    result[index++] = rightVal;
                    right--;
                }
            }
        }      
        return result;
    }
};
int main() {
    Solution sol;
    
    vector<int> arr1 = {-4, -2, 0, 2, 4};
    int A1 = 1, B1 = 3, C1 = 5;
    vector<int> result1 = sol.sortArray(arr1, A1, B1, C1);
    for (int num : result1) cout << num << " ";
    cout << endl; 

    vector<int> arr2 = {-3, -1, 2, 4};
    int A2 = -1, B2 = 0, C2 = 0;
    vector<int> result2 = sol.sortArray(arr2, A2, B2, C2);
    for (int num : result2) cout << num << " ";
    cout << endl; 

    vector<int> arr3 = {0};
    int A3 = 0, B3 = 0, C3 = 0;
    vector<int> result3 = sol.sortArray(arr3, A3, B3, C3);
    for (int num : result3) cout << num << " ";
    cout << endl; 

    vector<int> arr4 = {-10, -5, 0, 5, 10};
    int A4 = 1, B4 = 0, C4 = 0;
    vector<int> result4 = sol.sortArray(arr4, A4, B4, C4);
    for (int num : result4) cout << num << " ";
    cout << endl; 

    return 0;
}
