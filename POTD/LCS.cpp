#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];

    int LCS(int i, int j, string &s1, string &s2) {
        // Base case: If either string is fully traversed
        if (i == s1.size() || j == s2.size()) return 0;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, increment LCS length
        if (s1[i] == s2[j]) 
            return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);
        else 
            return dp[i][j] = max(LCS(i, j + 1, s1, s2), LCS(i + 1, j, s1, s2));
    }

    int lcs(string &s1, string &s2) {
        memset(dp, -1, sizeof(dp));  // Initialize dp array with -1
        return LCS(0, 0, s1, s2);
    }
};

int main() {
    Solution obj;
    string s1, s2;
    
    // Take input from user
    cout << "Enter first string: ";
    cin >> s1;
    
    cout << "Enter second string: ";
    cin >> s2;

    // Compute and print LCS length
    cout << "Length of Longest Common Subsequence: " << obj.lcs(s1, s2) << "\n";

    return 0;
}
