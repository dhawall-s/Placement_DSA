#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current) {
    if (index == nums.size()) {
        cout << "[";
        for (int i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i != current.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        return;
    }

    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current);

    current.pop_back();
    generateSubsets(nums, index + 1, current);
}

int main() {
    vector<int> nums = {1, 2};
    vector<int> current;

    cout << "Subsets:\n";
    generateSubsets(nums, 0, current);

    return 0;
}
