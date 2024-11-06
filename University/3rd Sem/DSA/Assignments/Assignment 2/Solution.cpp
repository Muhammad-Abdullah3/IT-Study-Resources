#include <iostream>
using namespace std;

double findMedianSortedArrays(int class1[], int size1, int class2[], int size2) {
    int totalSize = size1 + size2;
    int medianIndex1 = (totalSize - 1) / 2;
    int medianIndex2 = totalSize / 2;
    
    int i = 0, j = 0, count = 0;
    int current = 0, previous = 0;

    while (count <= medianIndex2) {
        previous = current;
        
        if (i < size1 && (j >= size2 || class1[i] <= class2[j])) {
            current = class1[i];
            i++;
        } else {
            current = class2[j];
            j++;
        }
        
        count++;
    }

    
    if (totalSize % 2 == 1) {
        return current;
    }
    return (previous + current) / 2.0;
}

int main() {
    int class1[] = {55, 70, 85};
    int class2[] = {60, 75, 90, 100};
    int size1 = sizeof(class1) / sizeof(class1[0]);
    int size2 = sizeof(class2) / sizeof(class2[0]);
    
    double median = findMedianSortedArrays(class1, size1, class2, size2);
    cout << "Median = " << median << endl;

    return 0;
}
