#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
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

    int peek() {
        return isEmpty() ? -1 : top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int evaluatePostfix(const string& expression) {
    Stack s;

    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.peek(); s.pop();
            int val1 = s.peek(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.peek();
}

int main() {
    string postfix = "231*+9-";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
    string postfix2 = "431*+9+2/";
    cout << "Postfix Expression 2: " << postfix2 << endl;
    cout << "Evaluation Result 2: " << evaluatePostfix(postfix2) << endl;
    return 0;
}
