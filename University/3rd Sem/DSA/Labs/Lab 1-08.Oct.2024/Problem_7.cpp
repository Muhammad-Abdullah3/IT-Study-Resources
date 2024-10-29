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

    
    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Function to find the second largest element
    int findSecondLargest() {
        // Since the array is sorted, the second largest element will be the second last element
        if (size < 2) {
            cout << "Array must have at least two elements to find the second largest." << endl;
            return -1;
        }
        return arr[size - 2];
    }

    
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Lab2 l2(size);

    
    l2.inputArray();

    l2.sortArray();


    int secondLargest = l2.findSecondLargest();
    cout << "The second largest element is: " << secondLargest << endl;

    return 0;
}
