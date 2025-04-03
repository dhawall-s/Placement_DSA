#include <iostream>
#include <algorithm> 
#include <vector>
int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50};

    int key = 30;
    auto lb = std::lower_bound(arr.begin(), arr.end(), key);
    std::cout << "Lower Bound of " << key << " is at index: " << (lb - arr.begin()) << std::endl;
    auto ub = std::upper_bound(arr.begin(), arr.end(), key);
    std::cout << "Upper Bound of " << key << " is at index: " << (ub - arr.begin()) << std::endl;
    return 0;
}
