#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumPoint(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0, leftSum = 0;

    // Step 1: Compute the total sum of the vector
    for (int num : arr) {
        totalSum += num;
    }

    // Step 2: Iterate and check for equilibrium point
    for (int i = 0; i < n; i++) {
        // Right sum = totalSum - leftSum - arr[i]
        if (leftSum == totalSum - leftSum - arr[i]) {
            return i; // Return the equilibrium index
        }
        leftSum += arr[i]; // Update left sum
    }

    return -1; // No equilibrium point found
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};

    int equilibriumIndex = findEquilibriumPoint(arr);
    
    if (equilibriumIndex != -1) {
        cout << "Equilibrium index: " << equilibriumIndex << endl;
    } else {
        cout << "No equilibrium index found" << endl;
    }

    return 0;
}
