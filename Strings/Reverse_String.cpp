#include <iostream>
#include <algorithm> // for reverse()
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;
    return 0;
}
