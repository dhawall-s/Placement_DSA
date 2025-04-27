#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiplyStrings(string& s1, string& s2) {
        bool negative = false;
        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }
        
        // Remove leading zeros
        while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);
        
        // If any string is "0"
        if (s1 == "0" || s2 == "0") return "0";
        
        int n = s1.size();
        int m = s2.size();
        vector<int> result(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string res = "";
        for (int num : result) {
            if (!(res.empty() && num == 0)) {
                res.push_back(num + '0');
            }
        }
        
        if (negative) res = "-" + res;
        return res;
    }
};

// Sample usage
int main() {
    Solution solution;
    string s1, s2;
    cout << "Enter first number: ";
    cin >> s1;
    cout << "Enter second number: ";
    cin >> s2;
    
    string result = solution.multiplyStrings(s1, s2);
    cout << "Product: " << result << endl;
    
    return 0;
}
