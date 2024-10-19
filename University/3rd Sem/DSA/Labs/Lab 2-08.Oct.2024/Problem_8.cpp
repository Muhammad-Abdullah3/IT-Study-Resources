#include<iostream>
using namespace std;
int prob8(int arr[],int size)
{
    int sum = 0;
    for(int i=0;i<size;i+=2)
    {
        sum = sum+arr[i];
    }
    return sum;
}
int main()
{
    int size = 6;
    int arr[size];
    cout<<"Enter elements of Array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Sum of elements at even indicies = "<<prob8(arr,size);
    return 0;
}