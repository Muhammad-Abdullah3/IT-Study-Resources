#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
        Node(char value) : data(value), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    char peek() {
        return isEmpty() ? '\0' : top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isBalanced(const string& str) {
    Stack s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.peek();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string input1 = "({[()]})";
    string input2 = "({[([)])})";

    cout << input1 << " => " << (isBalanced(input1) ? "Balanced" : "Not Balanced") << endl;
    cout << input2 << " => " << (isBalanced(input2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
