#include<iostream>
using namespace std;
class Lab2 {
    public:
    void prob3(int arr[]) {

        int size = sizeof(arr);
        for(int i=0;i<size;i++)
        {
            if(arr[i]%2==0)
            {
                cout<<arr[i]<<endl;
            }
        }
    }
};
int main() {
    Lab2 obj;
    int arr[8]={19,20,32,1123,238,899,18,93};
    obj.prob3(arr);
    return 0;
}