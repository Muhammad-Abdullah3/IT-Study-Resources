#include <iostream>
using namespace std;

class Lab2 {
private:
    int* arr1;
    int* arr2;
    int* arr3;
    int size1, size2, size3;

public:
    Lab2(int s1, int s2, int s3) {
        size1 = s1;
        size2 = s2;
        size3 = s3;
        arr1 = new int[size1];
        arr2 = new int[size2];
        arr3 = new int[size3];
    }

    void inputArrays() {
        cout << "Enter the elements of the first array: " << endl;
        for (int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter the elements of the second array : " << endl;
        for (int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }

        cout << "Enter the elements of the third array: " << endl;
        for (int i = 0; i < size3; i++) {
            cin >> arr3[i];
        }
    }

    void findCommonElements() {
        cout << "Common elements are: ";

        for (int i = 0; i < size1; i++) {
            bool foundInSecond = false, foundInThird = false;

            for (int j = 0; j < size2; j++) {
                if (arr1[i] == arr2[j]) {
                    foundInSecond = true;
                    break;
                }
            }

            for (int k = 0; k < size3; k++) {
                if (arr1[i] == arr3[k]) {
                    foundInThird = true;
                    break;
                }
            }

            if (foundInSecond && foundInThird) {
                cout << arr1[i] << " ";
            }
        }

        cout << endl;
    }
};

int main() {
    int size1, size2, size3;
    
    cout << "Enter the size of the first array: ";
    cin >> size1;
    
    cout << "Enter the size of the second array: ";
    cin >> size2;
    
    cout << "Enter the size of the third array: ";
    cin >> size3;

    Lab2 l2(size1, size2, size3);

    l2.inputArrays();

    l2.findCommonElements();

    return 0;
}
