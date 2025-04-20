#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            int len = s.size();
            if (len % 2 != 0) continue;

            int half = len / 2;
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < half; ++j) sum1 += s[j] - '0';
            for (int j = half; j < len; ++j) sum2 += s[j] - '0';

            if (sum1 == sum2) ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    int low1 = 1, high1 = 100;
    cout << "Symmetric integers between " << low1 << " and " << high1 << ": " 
         << sol.countSymmetricIntegers(low1, high1) << endl;

    int low2 = 1200, high2 = 1230;
    cout << "Symmetric integers between " << low2 << " and " << high2 << ": " 
         << sol.countSymmetricIntegers(low2, high2) << endl;

    return 0;
}
