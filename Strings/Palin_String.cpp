#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string s) {
    stack<char> st;
    for (char ch : s)
        st.push(ch);

    for (char ch : s) {
        if (ch != st.top())
            return false;
        st.pop();
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}
