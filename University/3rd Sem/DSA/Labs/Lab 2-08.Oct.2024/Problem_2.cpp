#include<iostream>
using namespace std;
class Lab2 {
    public:
    int prob2(int arr[],int target) {
        int size = sizeof(arr);
        int count =0;
        for(int i=0;i<size;i++)
        {
            if(target==arr[i])
            {
                count++;
            }
        }
        return count;  
    }
};
int main() {
    Lab2 obj;
    int arr[8]={19,20,32,1123,238,899,89,20};
    int target = 20;
    cout<<target<<" is found "<<obj.prob2(arr,target)<<" times.";
    return 0;
}