#include<iostream>
using namespace std;


class DoubleLinkList {
    //for Link List operations
     // Creating a link list
    private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value): data(value), next(nullptr),prev(nullptr){}
    };
    public:
    Node* head;
    Node*tail;
    DoubleLinkList(): head(nullptr),tail(nullptr){}
    // Inserting a node at the end of the list
    void insertAtEnd(int value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
            tail = newN;
            return;
        }
        Node* temp = head;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newN; 
        newN->prev = temp;
    }

    // Inserting a node at the start of the list
    void insertAtStart(int value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
            tail = newN;
            return;
        }
        Node* temp = head;
        head = newN;
        newN->next = temp;
        temp->prev=newN;
    }
    // Inserting a node after a specific position of the list
    void insertAfterPos(int pos,int value) {
        Node* newN = new Node(value);
        Node* temp = head;
        if (pos<1) {
            cout<<"Invalid Position";
            return;
        }
        if (pos == 1) {
            newN->next = temp;
            head = newN;
            temp->prev=newN;
            return;
        }
        int count =1;
        while(count<pos-1&&temp!=nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout<<"Invalid Position";
            return;
        }
        newN->next=temp->next;
        temp->next=newN;
        newN->prev=temp;
    }
    // inserting before a position
     void insertbeforePos(int pos,int value) {
        Node* newN = new Node(value);
        Node* temp = head;
        if (pos<1) {
            cout<<"Invalid Position";
            return;
        }
        if (pos == 1) {
            newN->next = temp;
            head = newN;
            temp->prev=newN;
            return;
        }
        int count =1;
        while(count<pos-1&&temp!=nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout<<"Invalid Position";
            return;
        }
        newN->next=temp;
        newN->prev=temp->prev;
        temp->prev=newN;
    }
    // Function to delete a node from the end of the linked list
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty.";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node from the beginning of the linked list
    void deleteStart() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete a node at a specific position
    void deletePos(int pos) {
        if ( pos <1 ||head == nullptr ) {
            cout << "Position is out of bounds or list is empty.\n";
            return;
        }

        if (pos == 1) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count=1;
        while (count<pos - 1 && temp->next->next != nullptr) {
            temp = temp->next;
            count++;
        }

        if (temp->next == nullptr) {
            cout << "Position is out of bounds"<<endl;
            return;
        } 
        Node* nodeDel = temp->next;
        temp->next = temp->next->next;
        delete nodeDel;   
    }
      // Function to delete a node By its value
    void deleteVal(int value) {
        if (head == nullptr ) {
            cout << "List is empty"<<endl;
            return;
        }

        if (head->data==value) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next!=nullptr&&temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout <<value<<" not found in the list"<<endl;
            return;
        } 
        Node* nodeDel = temp->next;
        temp->next = temp->next->next;
        delete nodeDel;   
    }
    // Searching the link list and fetching the position of element
    int find(int value) {
        Node* temp = head;
        int count =1;
        while (temp!=nullptr) {
            if(temp->data==value) {
                return count;
            }
            temp = temp->next;
            count++;
        }
        return -1;
    }

    // printing our link lis
    void displayLinkList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main() {
    DoubleLinkList dll;
    dll.insertAtStart(10);
    dll.insertAtStart(20);
    dll.insertAtStart(30);
    dll.insertAtEnd(70);
    dll.insertAfterPos(3,40);
    dll.displayLinkList(dll.head);
    if(dll.find(40)!=-1)
        cout<<"40 is found on position " << dll.find(40)<<endl;
    else
        cout<<"40 is not found in the list"<<endl;
    dll.displayLinkList(dll.head);
    return 0;
}