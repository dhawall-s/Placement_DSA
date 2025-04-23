#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> group(37, 0);
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            group[sum]++;
        }

        int maxSize = *max_element(group.begin(), group.end());
        int count = 0;
        for (int size : group) {
            if (size == maxSize) count++;
        }

        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    int result = sol.countLargestGroup(n);
    cout << "Output: " << result << endl;
    return 0;
}
