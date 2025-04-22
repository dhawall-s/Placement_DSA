#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long power(long long x, long long y) {
        long long res = 1;
        while (y > 0) {
            if (y % 2) res = res * x % MOD;
            x = x * x % MOD;
            y /= 2;
        }
        return res;
    }

    int idealArrays(int n, int maxValue) {
        const int MAX_LEN = 14; // Max length of multiplicative chains due to constraints
        vector<vector<int>> cnt(MAX_LEN + 1, vector<int>(maxValue + 1, 0));

        // Base case: single-element arrays
        for (int i = 1; i <= maxValue; ++i) {
            cnt[1][i] = 1;
        }

        // DP: build sequences of increasing length where arr[i] % arr[i-1] == 0
        for (int len = 2; len <= MAX_LEN; ++len) {
            for (int x = 1; x <= maxValue; ++x) {
                for (int y = x * 2; y <= maxValue; y += x) {
                    cnt[len][y] = (cnt[len][y] + cnt[len - 1][x]) % MOD;
                }
            }
        }

        // Precompute factorials and inverse factorials for combinations
        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        auto comb = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        // Final answer: for each valid sequence length and ending value
        long long result = 0;
        for (int len = 1; len <= MAX_LEN; ++len) {
            long long ways = comb(n - 1, len - 1);
            for (int v = 1; v <= maxValue; ++v) {
                result = (result + cnt[len][v] * ways % MOD) % MOD;
            }
        }

        return result;
    }
};

// Sample main function to test the solution
int main() {
    Solution sol;
    
    int n1 = 2, maxValue1 = 5;
    cout << "Input: n = " << n1 << ", maxValue = " << maxValue1 << "\n";
    cout << "Output: " << sol.idealArrays(n1, maxValue1) << "\n"; // Expected: 10

    int n2 = 5, maxValue2 = 3;
    cout << "Input: n = " << n2 << ", maxValue = " << maxValue2 << "\n";
    cout << "Output: " << sol.idealArrays(n2, maxValue2) << "\n"; // Expected: 11

    return 0;
}
