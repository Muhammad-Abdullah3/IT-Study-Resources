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
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    
    void rotateArray(int num) {
        num = num % size; 
        int* temp = new int[size];
        
        for (int i = 0; i < size; i++) {
            temp[i] = arr[(i + num) % size];
        }
        
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }

        delete[] temp;
    }

    // Function to display the array
    void displayArray() const {
        cout << "Array after rotation: " << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Lab2 l2(size);

    l2.inputArray();

    int num;
    cout << "Enter the number of rotations to perform: ";
    cin >> num;

    l2.rotateArray(num);
    l2.displayArray();

    return 0;
}
