#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (auto& d : dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count += freq[key];
            freq[key]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> dominoes1 = {{1,2},{2,1},{3,4},{5,6}};
    vector<vector<int>> dominoes2 = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    
    cout << "Output 1: " << sol.numEquivDominoPairs(dominoes1) << endl;
    cout << "Output 2: " << sol.numEquivDominoPairs(dominoes2) << endl; 

    return 0;
}
