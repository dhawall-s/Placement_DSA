#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int rotationsTop = 0;
        int rotationsBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return -1;
            } else if (tops[i] != x) {
                rotationsTop++;
            } else if (bottoms[i] != x) {
                rotationsBottom++;
            }
        }
        return min(rotationsTop, rotationsBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1 || tops[0] == bottoms[0]) {
            return result;
        } else {
            return check(bottoms[0], tops, bottoms);
        }
    }
};

int main() {
    Solution sol;

    vector<int> tops1 = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms1 = {5, 2, 6, 2, 3, 2};
    cout << "Example 1 Output: " << sol.minDominoRotations(tops1, bottoms1) << endl; // Expected: 2

    vector<int> tops2 = {3, 5, 1, 2, 3};
    vector<int> bottoms2 = {3, 6, 3, 3, 4};
    cout << "Example 2 Output: " << sol.minDominoRotations(tops2, bottoms2) << endl; // Expected: -1

    return 0;
}
