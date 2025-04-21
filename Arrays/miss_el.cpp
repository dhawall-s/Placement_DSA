#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size();
        long long expected_sum = (n + 1) * (n + 2) / 2;
        long long actual_sum = 0;
        for (int num : arr) {
            actual_sum += num;
        }
        return expected_sum - actual_sum;
    }
};

int main() {
    Solution sol;

    // Small Test Case
    vector<int> arr1 = {1, 2, 3, 5};
    cout << "Missing number: " << sol.missingNum(arr1) << endl;  // Output: 4

    // Large Test Case (simulate with partial vector for now)
    vector<int> arr2;
    for (int i = 1; i <= 1000000; ++i) {
        if (i != 91086) arr2.push_back(i);  // skip one number
    }
    cout << "Missing number in large test: " << sol.missingNum(arr2) << endl;  // Output: 91086

    return 0;
}
