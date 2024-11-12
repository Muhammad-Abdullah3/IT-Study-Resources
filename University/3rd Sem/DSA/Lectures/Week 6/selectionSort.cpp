#include<iostream>
using namespace std;
void selectionSort(int arr[],int size) {
    int min = arr[0];
    
    for(int i=0;i<size;i++) {
        int index = i;
        for(int j=i+1;j<size;j++) {
            if(arr[i]>arr[j]) {
                min =  arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
        
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
    selectionSort(arr,size);
    cout << "Sorted array: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}