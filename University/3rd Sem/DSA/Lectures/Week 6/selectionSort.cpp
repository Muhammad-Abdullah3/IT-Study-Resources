#include<iostream>
#include<vector>
#include<string>
using namespace std;
void selectionSort(vector<int>arr) {
    int size = arr.size();
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
    cout << "Sorted array: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
}

void selectionSortDesc(vector<int>arr) {
    int size = arr.size();
    int max = arr[0];
    
    for(int i=0;i<size;i++) {
        int index = i;
        for(int j=i+1;j<size;j++) {
            if(arr[i]<arr[j]) {
                max =  arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = max;
        arr[index] = temp;
        
    }
    cout << "Sorted array in descending: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
}

void SelectionSortString(vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j <arr.size(); j++) {
            if (arr[j].length() < arr[min].length()) {
                min= j;
            }
        }
     
        swap(arr[i], arr[min]);

    }
    cout << "\nSorted array String: ";
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};
    int size = arr.size();
     cout << "UnSorted array: ";
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
        }
    cout<<endl;
    selectionSort(arr);
    

    vector<int> arr2 = {-12, 104, 2, 1, 10};
    cout << "UnSorted array: ";
    for(int i=0;i<arr2.size();i++) {
        cout << arr2[i] << " ";
        }
    cout<<endl;
    selectionSortDesc(arr2);

    vector<string> arr3 = {"Abdullah","Faizan","Waheed","Zaryab","Feroze","Faseh"};
    cout << "\nUnSorted array: ";
    for(int i=0;i<arr3.size();i++) {
        cout << arr3[i] << " ";
        }
    cout<<endl;

    SelectionSortString(arr3);
    
    return 0;
}