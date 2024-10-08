#include<iostream>
using namespace std;
void prob4(int arr[],int size)
{
    bool isdup = false;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;i<size;i++)
        {
            if(arr[i]==arr[j])
            {
                isdup = true;
            }
            else {
                isdup = false;
            }
        }
        if(!isdup)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int main() {
    int size = 9;
    int arr[size] = {1, 2, 3, 4, 5,4,2,9,10};
    prob4(arr,size);
    return 0;
}