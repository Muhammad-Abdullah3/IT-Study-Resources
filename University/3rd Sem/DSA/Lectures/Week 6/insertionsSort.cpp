#include<iostream>
using namespace std;
void insertionSort(int arr[],int size) {
    for(int i=1;i<size;i++) {
        for(int j=0;j<i;j++) {
            if(arr[j]>arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
     cout << "UnSorted array: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
        }
    cout<<endl;
    insertionSort(arr,size);
    cout << "Sorted array: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}