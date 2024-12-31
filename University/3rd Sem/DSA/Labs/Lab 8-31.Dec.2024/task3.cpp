#include <iostream>
#include <stack>
using namespace std;

// Function to check if the parentheses are balanced
bool isBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // Check for closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty or the top of the stack does not match the current closing bracket
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack is empty, it means all brackets were balanced
    return s.empty();
}

int main() {
    string input;

    // Test case 1
    input = "({[()]})";
    cout << input << endl;
    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    // Test case 2
    input = "({[([)])}";
    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}