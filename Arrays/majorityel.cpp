#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int candidate = -1;

        // Phase 1: Find a candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Phase 2: Verify the candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate)
                count++;
        }

        if (count > arr.size() / 2)
            return candidate;
        else
            return -1;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 1, 2, 1, 3, 5, 1};
    cout << "Majority Element (Test 1): " << sol.majorityElement(arr1) << endl;

    // Test case 2
    vector<int> arr2 = {7};
    cout << "Majority Element (Test 2): " << sol.majorityElement(arr2) << endl;

    // Test case 3
    vector<int> arr3 = {2, 13};
    cout << "Majority Element (Test 3): " << sol.majorityElement(arr3) << endl;

    return 0;
}
