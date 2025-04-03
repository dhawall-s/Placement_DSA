#include <iostream>
using namespace std;

int findPeakElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1]) 
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, n);
    cout << "Peak element is at index: " << peakIndex << endl;
    
    return 0;
}
