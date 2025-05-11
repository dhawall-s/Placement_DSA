#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];
                if (minHeap.size() < k) {
                    minHeap.push(sum);
                } else if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        return minHeap.top();
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.kthLargest(arr, k) << endl;
    return 0;
}
