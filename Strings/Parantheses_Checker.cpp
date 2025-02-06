#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false; // Closing bracket with no matching opening bracket
            
            char top = st.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                st.pop(); // Matching pair found
            } else {
                return false; // Mismatched parentheses
            }
        }
    }

    return st.empty(); // If stack is empty, all brackets are matched
}

int main() {
    string s;
    cout << "Enter a string with parentheses: ";
    cin >> s;

    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
