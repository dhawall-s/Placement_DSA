#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& arr, int target, vector<int>& combination, int start) {
    if (target == 0) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        if (arr[i] > target) {
            continue;
        }

        combination.push_back(arr[i]);
        findCombinations(arr, target - arr[i], combination, i);
        combination.pop_back();
    }
}

int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    int x;
    cin >> x; 

    sort(arr.begin(), arr.end());

    vector<int> combination;
    bool found = false;

    findCombinations(arr, x, combination, 0);

    if (combination.empty()) {
        cout << "Empty" << endl;
    }

    return 0;
}