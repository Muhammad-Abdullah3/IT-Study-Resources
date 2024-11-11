#include <iostream>
#include<vector>
using namespace std;

float findMedian(vector<int> vect1,vector<int> vect2) {
    int size1 = vect1.size();
    int size2 = vect2.size();
    int newSize = size1 + size2;
    
    int vect1Count = 0; 
    int vect2Count = 0; 
    int loopCount = 0;
    int currentMedian = 0;
    int previousMedian = 0;

    while (loopCount <= newSize/2) {
        previousMedian = currentMedian;
        
        if (vect1Count < size1 && (vect2Count >= size2 || vect1[vect1Count] <= vect2[vect2Count])) {
            currentMedian = vect1[vect1Count];
            vect1Count++;
        } else {
            currentMedian = vect2[vect2Count];
            vect2Count++;
        }
        
        loopCount++;
    }

    
    if (newSize % 2 == 0) {
        return (previousMedian + currentMedian) / 2.0;
    }
    else {
        return currentMedian;
    }
}

int main() {
    vector<int> vect1 = {55, 70, 85,95};
    vector<int> vect2 = {60, 75, 90, 100};
    vector<int> vect3 = {55, 70, 85};
    cout<<"Test Case 1"<<endl;
    float median = findMedian(vect3, vect2);// {55,60,70,75,85,90,95,100}
    cout << "Median = " << median << endl;

    cout<<"Test Case 2"<<endl;
    float median2 = findMedian(vect1, vect2);// {55,60,70,75,85,90,95,100}
    cout << "Median = " << median2 << endl;

    return 0;
}
