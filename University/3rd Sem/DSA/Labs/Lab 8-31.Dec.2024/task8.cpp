#include <iostream>
#include <vector>
using namespace std;
class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow: No elements to pop" << endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return value;
    }

    int nextGreatest() {
        if (top == nullptr) {
            cout << "Stack is empty: No element to peek" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

vector<int> findNextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);

    Stack stack;

    for (int i = 0; i < n; i++) {
        while (!stack.isEmpty() && arr[stack.nextGreatest()] < arr[i]) {
            int index = stack.pop();
            result[index] = arr[i];
        }
        stack.push(i);
    }
    return result;
}

void printVector(vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 5, 2, 10};
    cout << "Input Array: ";
    printVector(arr);

    vector<int> result = findNextGreaterElements(arr);

    cout << "Next Greater Elements: ";
    printVector(result);

    return 0;
}
