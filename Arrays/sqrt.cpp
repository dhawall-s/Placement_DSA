#include <iostream>
using namespace std;

int squareRoot(int x) {
    if (x == 0 || x == 1) return x;

    int low = 1, high = x, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid == x) return mid;
        else if (mid * mid < x) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return ans;  
}

int main() {
    int x = 37;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    return 0;
}
