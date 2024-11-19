#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

int partitionPivotFirst(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[low];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low+1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[low], arr[i]);  
    return i;
}


// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partitionPivotFirst(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partitionEven(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the pivot as the last element
    int i = low - 1;  // Pointer for the smaller element

    // Loop through the array and rearrange elements
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with arr[i + 1]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Return the partition index
}

// QuickSort function
void quickSortEven(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition the array
        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high);  // Sort the right part
    }
}

// Function to sort only the even numbers and keep odd numbers at their positions
void sortEvenNumbers(vector<int>& arr) {
    
    vector<int> evenNumbers;
    for (int num : arr) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        }
    }

    
    quickSort(evenNumbers, 0, evenNumbers.size() - 1);

    
    int evenIndex = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            arr[i] = evenNumbers[evenIndex++];
        }
    }
}


int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    vector<int> arr2 = {3,5,6,12,9,32,44,11};
    cout<<endl;
    int n2 = arr2.size();
    sortEvenNumbers(arr2);
    
     for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
