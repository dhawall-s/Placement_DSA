#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    current += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            // Add the last group
            current += to_string(count) + result.back();
            result = current;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    string output = sol.countAndSay(n);
    cout << "The " << n << "th term in the Look-and-Say sequence is: " << output << endl;
    
    return 0;
}
