#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;
            for (int num : arr) {
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.getSingle(arr);
    cout << "Single element is: " << result << endl;
    return 0;
}
