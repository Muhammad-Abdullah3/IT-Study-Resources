#include<iostream>
using namespace std;

struct Node {
        int data;
        Node* next;
        Node(int value): data(value), next(nullptr){}
    };
class SingleLinkList {
    //for Link List operations
     // Creating a link list
    private:
    struct Node {
        int data;
        Node* next;
        Node(int value): data(value), next(nullptr){}
    };
    public:
    Node* head;
    SingleLinkList(): head(nullptr){}
    // Inserting a node at the end of the list
    void insertAtEnd(int value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
            return;
        }
        Node* temp = head;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newN;   
    }

    // Inserting a node at the start of the list
    void insertAtStart(int value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
            return;
        }
        Node* temp = head;
        head = newN;
        newN->next = temp;
    }

    // printing our link lis
    void displayLinkList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
            }
    }

};

int main() {
    SingleLinkList sll;
    sll.insertAtStart(10);
    sll.insertAtStart(20);
    sll.insertAtStart(30);
    sll.displayLinkList(sll.head);
    return 0;
}