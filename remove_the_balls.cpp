#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> st;
        int n = color.size();

        for (int i = 0; i < n; ++i) {
            if (!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
                st.pop();
            } else {
                st.push({color[i], radius[i]});
            }
        }

        return st.size();
    }
};

int main() {
    Solution sol;
    
    vector<int> color1 = {2, 3, 5};
    vector<int> radius1 = {3, 3, 5};
    cout << "Output 1: " << sol.findLength(color1, radius1) << endl;

    vector<int> color2 = {2, 2, 5};
    vector<int> radius2 = {3, 3, 5};
    cout << "Output 2: " << sol.findLength(color2, radius2) << endl;

    return 0;
}
