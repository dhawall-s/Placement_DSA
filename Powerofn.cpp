#include <iostream>
#include <climits>
using namespace std;

class Solution {
  public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        for (int i = 2; i * i <= k; ++i) {
            int count = 0;
            while (k % i == 0) {
                k /= i;
                count++;
            }
            if (count > 0) {
                int temp = 0, p = i;
                while (p <= n) {
                    temp += n / p;
                    p *= i;
                }
                ans = min(ans, temp / count);
            }
        }
        if (k > 1) {
            int temp = 0, p = k;
            while (p <= n) {
                temp += n / p;
                p *= k;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    int result = sol.maxKPower(n, k);
    cout << "Maximum power x such that k^x divides n! is: " << result << endl;
    return 0;
}
