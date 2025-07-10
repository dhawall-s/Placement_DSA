#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string longestString(vector<string> &words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        string result = "";
        for (const string &word : words) {
            bool valid = true;
            for (int i = 1; i <= word.length(); i++) {
                if (!wordSet.count(word.substr(0, i))) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<string> words1 = {"p", "pr", "pro", "probl", "problem", "pros", "process", "processor"};
    vector<string> words2 = {"ab", "a", "abc", "abd"};

    Solution sol;
    cout << sol.longestString(words1) << endl;  // Output: pros
    cout << sol.longestString(words2) << endl;  // Output: abc

    return 0;
}
