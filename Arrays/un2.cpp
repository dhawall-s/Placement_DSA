#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xorAll = 0;
        for (int num : arr) {
            xorAll ^= num;
        }

        int rightmostSetBit = xorAll & -xorAll;

        int num1 = 0, num2 = 0;
        for (int num : arr) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        if (num1 < num2) {
            return {num1, num2};
        } else {
            return {num2, num1};
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> result = sol.singleNum(arr);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
