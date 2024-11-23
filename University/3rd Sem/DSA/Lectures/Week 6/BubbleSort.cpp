#include<iostream> 
#include<vector>
using namespace std;
void bubbleSort(vector<int> vect) {
    for(int i=0;i<vect.size();i++) {
        for(int j=1;j<vect.size()-i-1;j++) {
            if(vect[i]>vect[j]) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = vect[i];
            }
        }
    }
}

int main() {
    
}