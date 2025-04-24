#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<int> windowSet;
            for (int j = i; j < n; ++j) {
                windowSet.insert(nums[j]);
                if (windowSet.size() == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};
