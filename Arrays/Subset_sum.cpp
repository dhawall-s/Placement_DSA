#include <iostream>
#include <vector>
using namespace std;
bool isSubsetSum(vector<int>& arr, int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (isSubsetSum(arr, n, m))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
