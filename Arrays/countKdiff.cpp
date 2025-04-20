// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int countKDifference(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         int count = 0;

//         for (int num : nums) {
//             freq[num]++;
//         }

//         for (auto& [num, f] : freq) {
//             if (freq.count(num + k)) {
//                 count += f * freq[num + k];
//             }
//         }

//         return count;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> nums1 = {1, 2, 2, 1};
//     int k1 = 1;
//     cout << "Output: " << sol.countKDifference(nums1, k1) << endl;  // Output: 4

//     vector<int> nums2 = {1, 3};
//     int k2 = 3;
//     cout << "Output: " << sol.countKDifference(nums2, k2) << endl;  // Output: 0

//     vector<int> nums3 = {3, 2, 1, 5, 4};
//     int k3 = 2;
//     cout << "Output: " << sol.countKDifference(nums3, k3) << endl;  // Output: 3

//     return 0;
// }
