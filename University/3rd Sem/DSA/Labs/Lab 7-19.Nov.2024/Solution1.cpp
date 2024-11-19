#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value = 0, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* header; // Header node

public:
    SinglyLinkedList() {
        header = new Node(); // Initialize header node
    }

    ~SinglyLinkedList() {
        clear();
        delete header;
    }

    // Method to get the size of the list
    int size()  {
        int count = 0;
        Node* current = header->next;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Method to print the linked list
    void print() const {
        Node* current = header->next;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Method to check if a value x is in the linked list
    bool contains(int x)  {
        Node* current = header->next;
        while (current != nullptr) {
            if (current->data == x) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Method to add a value x if it's not already in the list
    void add(int x) {
        if (!contains(x)) {
            Node* newNode = new Node(x, header->next);
            header->next = newNode;
        }
    }

    // Method to remove a value x if it's in the list
    void remove(int x) {
        Node* current = header;
        while (current->next != nullptr) {
            if (current->next->data == x) {
                Node* toDelete = current->next;
                current->next = toDelete->next;
                delete toDelete;
                return;
            }
            current = current->next;
        }
    }

    // Clear the linked list
    void clear() {
        Node* current = header->next;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        header->next = nullptr;
    }
};

// Main function for testing
int main() {
    SinglyLinkedList list;

    // Adding elements
    list.add(10);
    list.add(20);
    list.add(30);

    // Print list
    cout << "List: ";
    list.print();

    // Size of the list
    cout << "Size: " << list.size() << endl;

    // Check if an element exists
    cout << "Contains 20: " << (list.contains(20) ? "Yes" : "No") << endl;

    // Remove an element
    list.remove(20);
    cout << "List after removing 20: ";
    list.print();

    // Add an existing element
    list.add(100);
    cout << "List after adding 100: ";
    list.print();

    // Clear the list
    list.clear();
    cout << "List after clearing: ";
    list.print();

    return 0;
}
