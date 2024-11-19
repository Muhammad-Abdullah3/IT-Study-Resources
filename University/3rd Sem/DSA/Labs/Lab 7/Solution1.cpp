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

    int size()  {
        int count = 0;
        Node* current = header->next;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void print() {
        Node* current = header->next;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
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

   
    void add(int x) {
            Node* newNode = new Node(x, header->next);
            header->next = newNode;
    }

    
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

    return 0;
}
