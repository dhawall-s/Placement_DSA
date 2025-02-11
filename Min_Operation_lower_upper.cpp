#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int minOperationsToPair(string s) {
    unordered_map<char, int> lower, upper;
    
    // Count occurrences of lowercase and uppercase letters
    for (char c : s) {
        if (islower(c))
            lower[c]++;
        else
            upper[c]++;
    }

    int operations = 0;

    // Check for unpaired characters
    for (char c = 'a'; c <= 'z'; c++) {
        int lowerCount = lower[c];
        int upperCount = upper[c - 'a' + 'A'];
        operations += abs(lowerCount - upperCount); // Difference needs to be fixed
    }

    return operations / 2; // Each modification can fix one pair
}

int main() {
    string s = "abBA";
    cout << "Minimum operations: " << minOperationsToPair(s) << endl;
    return 0;
}
