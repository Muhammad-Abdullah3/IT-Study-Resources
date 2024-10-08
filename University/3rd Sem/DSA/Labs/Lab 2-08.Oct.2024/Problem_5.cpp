#include<iostream>
using namespace std;
bool isSorted(int arr[],int size)
{
    bool isSort = true;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {   
            if(arr[i]>arr[j])
            {
                isSort = false;
            }
        }
    }
    return isSort;
}
int main()
{
    int size = 10;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    if(isSorted(arr,size))
    {
        cout<<"Array is Sorted";
    }
    else
    {
        cout<<"Array is not Sorted";
    }
    return 0;
}