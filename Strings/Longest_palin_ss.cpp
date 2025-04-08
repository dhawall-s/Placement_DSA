#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<string> permutations;
    sort(s.begin(), s.end());
    do {
        permutations.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    for (const auto &perm : permutations) {
        cout << perm << endl;
    }
    return 0;
}
