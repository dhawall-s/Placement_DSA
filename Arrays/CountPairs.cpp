#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    int n, k;
    
    // Input size and value of k
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;
    
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = sol.countPairs(nums, k);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
