#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

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

    bool isEmpty() {
        return top == nullptr;
    }
};

ListNode* reverseList(ListNode* head) {
    Stack stack;

    // Push all elements of the list into the stack
    ListNode* current = head;
    while (current != nullptr) {
        stack.push(current->data);
        current = current->next;
    }

    // Create a new reversed list
    ListNode* dummy = new ListNode;
    dummy->data = 0;
    dummy->next = nullptr;

    ListNode* temp = dummy;

    while (!stack.isEmpty()) {
        ListNode* newNode = new ListNode;
        newNode->data = stack.pop();
        newNode->next = nullptr;

        temp->next = newNode;
        temp = temp->next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create the original linked list
    ListNode* head = new ListNode;
    head->data = 1;

    head->next = new ListNode;
    head->next->data = 2;

    head->next->next = new ListNode;
    head->next->next->data = 3;

    head->next->next->next = new ListNode;
    head->next->next->next->data = 4;
    head->next->next->next->next = nullptr;

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
