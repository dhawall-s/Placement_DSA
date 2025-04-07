#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int result = gcd(x, y);
    cout << "GCD is: " << result << endl;

    return 0;
}
