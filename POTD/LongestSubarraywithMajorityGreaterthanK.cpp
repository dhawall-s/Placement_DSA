#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> prefixIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < n; ++i) {
            sum += transformed[i];
            if (sum > 0) {
                maxLen = i + 1;
            } else {
                if (prefixIndex.find(sum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[sum - 1]);
                }
            }

            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.longestSubarray(arr, k) << endl;
    return 0;
}
