#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > arr[mid + 1]) {
                // Peak is in the left half (including mid)
                high = mid;
            } else {
                // Peak is in the right half
                low = mid + 1;
            }
        }
        
        return low; // Peak index
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        int idx = ob.peakElement(arr);

        // Output verification
        if (idx < 0 || idx >= n)
            cout << "false" << endl;
        else {
            bool isPeak = false;
            if (n == 1 || (idx == 0 && arr[idx] > arr[idx + 1]) || 
                (idx == n - 1 && arr[idx] > arr[idx - 1]) ||
                (arr[idx] > arr[idx - 1] && arr[idx] > arr[idx + 1])) {
                isPeak = true;
            }

            cout << (isPeak ? "true" : "false") << endl;
        }
    }
    return 0;
}
