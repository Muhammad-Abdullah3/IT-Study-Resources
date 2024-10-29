#include <iostream>
using namespace std;

class Lab2 {
private:
    int* arr;
    int size;

public:
    Lab2(int s) {
        size = s;
        arr = new int[size];
    }

    void inputArray() {
        cout << "Enter the elements of the array (between 1 and " << size - 1 << "): " << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    int findDuplicate() {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    return arr[i];
                }
            }
        }
        return -1;  // In case no duplicate is found
    }

    void displayArray() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array (n + 1): ";
    cin >> size;

    Lab2 lab2(size);

    lab2.inputArray();

    int duplicate = lab2.findDuplicate();
    if (duplicate != -1) {
        cout << "The duplicate element is: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}
