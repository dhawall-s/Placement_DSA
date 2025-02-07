#include <iostream>
#include <vector>
using namespace std;

void rotateByOne(vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: Store the last element
    int lastElement = arr[n - 1];

    // Step 2: Shift all elements to the right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Step 3: Place last element at the first position
    arr[0] = lastElement;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Read input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call function to rotate
    rotateByOne(arr);

    // Print rotated array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
