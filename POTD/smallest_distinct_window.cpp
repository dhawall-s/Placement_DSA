#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> uniqueChars(str.begin(), str.end());
        int totalUnique = uniqueChars.size();

        unordered_map<char, int> windowCount;
        int minLen = INT_MAX;
        int i = 0, matched = 0;

        for (int j = 0; j < str.length(); ++j) {
            windowCount[str[j]]++;

            if (windowCount[str[j]] == 1) {
                matched++;
            }

            // Try to shrink window from the left
            while (matched == totalUnique) {
                minLen = min(minLen, j - i + 1);

                windowCount[str[i]]--;
                if (windowCount[str[i]] == 0) {
                    matched--;
                }
                i++;
            }
        }

        return minLen;
    }
};

int main() {
    Solution obj;
    
    string input1 = "aabcbcdbca";
    string input2 = "aaab";
    string input3 = "geeksforgeeks";

    cout << "Input: " << input1 << " -> Output: " << obj.findSubString(input1) << endl;
    cout << "Input: " << input2 << " -> Output: " << obj.findSubString(input2) << endl;
    cout << "Input: " << input3 << " -> Output: " << obj.findSubString(input3) << endl;

    return 0;
}
