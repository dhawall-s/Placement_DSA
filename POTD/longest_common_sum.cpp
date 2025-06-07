#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = a1[i] - a2[i];
        }
        unordered_map<int, int> prefixSumIndex;
        int maxLen = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum == 0) {
                maxLen = i + 1;
            } else if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum]);
            } else {
                prefixSumIndex[sum] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> a1 = {0, 1, 0, 0, 0, 0};
    vector<int> a2 = {1, 0, 1, 0, 0, 1};

    Solution sol;
    int result = sol.longestCommonSum(a1, a2);
    cout << "Longest common span length: " << result << endl;
    return 0;
}
