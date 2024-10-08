#include<iostream>
using namespace std;
class Lab2 {
    public:
    double prob1(int arr[],int size) {
        double sum=0;
        for(int i=0;i<size;i++)
        {
            sum=sum+arr[i];
        }
        return sum;
    }
};
int main() {
    Lab2 obj;
    int arr[5]={1,2,3,4,5};
    double sum = obj.prob1(arr,5);
    cout<<sum;
    return 0;
}