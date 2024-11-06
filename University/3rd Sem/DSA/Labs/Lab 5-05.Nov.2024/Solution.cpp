#include<iostream>
using namespace std;
class Sorting {
    public:
    //bubble sort
    void bubbleSort(int arr[], int n) {//O(n^2)
        int temp = arr[0];
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[i]>arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout<<"Sorted Array: ";
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<"\t";
        }
    }
    //insertion sort
    void insertionSort(int arr[], int n) {//O(n^2)
        for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<"\t";
        }
    }
    //insertion sort in descending order
    void insertionSortDescending(int arr[], int n) {//O(n^2)
        for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout<<"Sorted Array in Descending: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<"\t";
        }
    }
    // bubble sort descending order
    void bubbleSortDescending(int arr[], int n) {//O(n^2)
        int temp = arr[0];
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[i]<arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout<<"Sorted Array in Descending: ";
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<"\t";
        }
    }
    // Bubble Sort Modified
    void bubbleSortModified(int arr[], int n) {//O(n^2)
        int temp = arr[0];
        int counter=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[i]>arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    counter++;
                }
            }
        }
        cout<<"Number of Swaps to Sort the Array: "<<counter;
    }
    // Insertion Sort Optimized
    void insertionSortOptimized(int arr[], int n) {//O(n log n)
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int tempArr[i];
            for (int k=0;k<i;k++) {
                tempArr[k] = arr[k];
            }
            int low = 0;
            int high = i-1;
            int index;
            int mid;
            while(low<=high) {
                mid = (low+high)/2;
                if(key==tempArr[mid]) {
                    index = mid+1;
                    break;
                }
                else if(key>tempArr[mid]) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
            if(low>mid) {
                index = low-1;
            }
            else {
                index = high+1;
            }


            // shifting and swapping
            int shifts = i-index;
            for(int j=0;j<shifts;j++) {
                arr[i-j] = arr[shifts-j-1];
            }
            //Assigning key to its index
            arr[index] = key;
    }

    cout<<"Sorted Array: ";
    for(int z=0;z<n;z++) {
        cout<<arr[z]<<"\t";
        }
    }
};

int main() {
    int arr[5] = {64, 34, 25, 12, 22};
    Sorting sort;
    cout<<"Unsorted Array: ";
    for(int i=0;i<5;i++) {
            cout<<arr[i]<<"\t";
    }
    cout<<endl;
    sort.bubbleSort(arr,5);
    cout<<endl;
    cout<<"Unsorted Array: ";
    int arr1[6] = {21, 13, 27, 54,0,5};
    for(int i=0;i<6;i++) {
            cout<<arr1[i]<<"\t";
    }
    cout<<endl;
    sort.insertionSort(arr1,6);


    int arr2[6] = {54, 12, 2, -1,23,102};
    cout<<"Unsorted Array: ";
    for(int i=0;i<6;i++) {
            cout<<arr2[i]<<"\t";
    }
    cout<<endl;
    sort.bubbleSortDescending(arr2,5);
    cout<<endl;
    cout<<"Unsorted Array: ";
    int arr3[6] = {21, 13, 27, 54,0,5};
    for(int i=0;i<6;i++) {
            cout<<arr3[i]<<"\t";
    }
    cout<<endl;
    sort.insertionSortDescending(arr3,6);
    cout<<endl;
    // Bubble sort modified
    sort.bubbleSortModified(arr1,6);
    cout<<endl;
    // Insertion Sort Optimized
    cout<<"Unsorted Array: ";
    int arr5[6] = {21, 13, 27, 54,10,5};
    for(int i=0;i<6;i++) {
            cout<<arr5[i]<<"\t";
    }
    cout<<endl;
    sort.insertionSortOptimized(arr5,6);
    cout<<endl;
    return 0;
}