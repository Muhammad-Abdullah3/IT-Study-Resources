#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node;
        if (!newNode) {
            cout << "Stack overflow: Unable to push " << value << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!top) {
            cout << "Stack underflow: No elements to pop" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    
};

int evaluatePostfix(string expression) {
    Stack stack;
    int length = expression.length();
    int result = 0;

    for (int i = 0; i < length; ++i) {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') {
            stack.push(ch - '0');
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            if (val1 == -1 || val2 == -1) {
                cout << "Error: Not enough operands in the stack" << endl;
                return -1;
            }
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            stack.push(result);
        }
    }
    return stack.pop();
}

int main() {
    string postfix = "231*+9-";
    int result = evaluatePostfix(postfix);
        cout << "Final Result: " << result << endl;
    return 0;
}
