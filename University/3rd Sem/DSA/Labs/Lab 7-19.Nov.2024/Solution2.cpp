#include <iostream>
#include <string>
using namespace std;

// Mobile class
class Mobile {
private:
    string brand;       // Brand name
    int unitsOnHand;    // Units in inventory
    double price;       // Retail price

public:
    // Constructor
    Mobile(string b = "", int u = 0, double p = 0.0) : brand(b), unitsOnHand(u), price(p) {}

    void setBrand(string b) { brand = b; }
    void setUnitsOnHand(int u) { unitsOnHand = u; }
    void setPrice(double p) { price = p; }

    string getBrand()  { return brand; }
    int getUnitsOnHand()  { return unitsOnHand; }
    double getPrice()  { return price; }

    void display()  {
        cout << "Brand: " << brand <<endl;
        cout<<"Units: " << unitsOnHand << endl;
        cout<<"Price: $" << price << endl;
    }
};

class Store {
private:
    struct Node {
        Mobile data; // Mobile object
        Node* next;  // Pointer to next node
        Node(Mobile m, Node* n = nullptr) : data(m), next(n) {}
    };

    Node* head; // Pointer to the start of the list

public:
    Store() : head(nullptr) {}

    ~Store() {
        clear();
    }

    // Insert a new mobile at the start
    void insertAtStart(const Mobile& mobile) {
        head = new Node(mobile, head);
    }

    // Insert a new mobile at the end
    void insertAtEnd(const Mobile& mobile) {
        if (!head) {
            head = new Node(mobile);
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(mobile);
        }
    }

    void insertAfter(int position,Mobile& mobile) {
        if (!head || position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position; i++) {
            if (!temp->next) {
                cout << "Position out of range!" << endl;
                return;
            }
            temp = temp->next;
        }

        temp->next = new Node(mobile, temp->next);
    }

    void deleteFromStart() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromPosition(int position) {
        if (!head || position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 0) {
            deleteFromStart();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (!temp->next || !temp->next->next) {
                cout << "Position out of range!" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display() const {
        if (!head) {
            cout << "Store is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
    }

    void clear() {
        while (head) {
            deleteFromStart();
        }
    }
};

int main() {
    Store store;

    Mobile m1("Samsung", 50, 799.99);
    Mobile m2("Apple", 30, 999.99);
    Mobile m3("OnePlus", 40, 699.99);

    store.insertAtStart(m1);
    cout << "After inserting at start:" << endl;
    store.display();

    // Insert at end
    store.insertAtEnd(m2);
    cout << "\nAfter inserting at end:" << endl;
    store.display();

    // Insert after position 0
    store.insertAfter(0, m3);
    cout << "\nAfter inserting after position 0:" << endl;
    store.display();

    store.deleteFromStart();
    cout << "\nAfter deleting from start:" << endl;
    store.display();


    store.deleteFromEnd();
    cout << "\nAfter deleting from end:" << endl;
    store.display();


    store.insertAtEnd(m1);
    store.insertAtEnd(m3);
    cout << "\nAfter Inserting At end again:" << endl;
    store.display();
    store.deleteFromPosition(1);
    cout << "\nAfter deleting from position 1:" << endl;
    store.display();

    return 0;
}
