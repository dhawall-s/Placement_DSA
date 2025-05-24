#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int sumSubstrings(string s) {
        int n = s.length();
        long long result = 0, prev = 0;

        for (int i = 0; i < n; ++i) {
            int num = s[i] - '0';
            prev = prev * 10 + (long long)(i + 1) * num;
            result += prev;
        }

        return (int)result;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.sumSubstrings(s) << endl;

    return 0;
}
