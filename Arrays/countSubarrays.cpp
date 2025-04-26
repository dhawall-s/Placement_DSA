#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1, maxPos = -1, badPos = -1; // track last positions

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                badPos = i; // invalid element found
            }
            if (nums[i] == minK) {
                minPos = i; // update last minK position
            }
            if (nums[i] == maxK) {
                maxPos = i; // update last maxK position
            }
            int validStart = min(minPos, maxPos);
            if (validStart > badPos) {
                ans += (validStart - badPos);
            }
        }
        return ans;
    }
};
