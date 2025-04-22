#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num; // XOR each number to cancel out duplicates
        }
        return result;
    }
};

// Example usage
int main() {
    Solution sol;

    vector<int> arr1 = {1, 2, 1, 5, 5};
    cout << "Unique number in arr1: " << sol.findUnique(arr1) << endl; // Output: 2

    vector<int> arr2 = {2, 30, 2, 15, 20, 30, 15};
    cout << "Unique number in arr2: " << sol.findUnique(arr2) << endl; // Output: 20

    return 0;
}
