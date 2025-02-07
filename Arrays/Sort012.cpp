#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Step 1: Count occurrences of 0, 1, and 2
    for (int num : arr) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else count2++;
    }

    // Step 2: Overwrite array
    int i = 0;
    while (count0--) arr[i++] = 0;  // Fill with 0s
    while (count1--) arr[i++] = 1;  // Fill with 1s
    while (count2--) arr[i++] = 2;  // Fill with 2s
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Read array input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call sorting function
    sort012(arr);

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
