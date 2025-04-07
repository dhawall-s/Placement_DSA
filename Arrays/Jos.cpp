#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 0; 
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter k (step count): ";
    cin >> k;

    int survivor = josephus(n, k) + 1; 
    cout << "The survivor is at position: " << survivor << endl;

    return 0;
}
