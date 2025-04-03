#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1; 
        } else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1; 
        } else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;

    return 0;
}
