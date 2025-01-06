#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* temp = head;
        LinkedList stack;

        while (temp) {
            stack.push(temp->data);
            temp = temp->next;
        }

        head = stack.head;
    }
};

int main() {
    LinkedList list;
    list.push(32);
    list.push(1);
    list.push(10);
    list.push(2);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
