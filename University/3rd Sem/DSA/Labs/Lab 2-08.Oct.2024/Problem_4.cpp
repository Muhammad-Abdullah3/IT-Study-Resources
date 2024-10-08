#include<iostream>
using namespace std;
void prob4(int arr[],int size)
{
    bool isdup = false;
    int indArr[size];
    for(int i=0;i<size;i++)
    {
        indArr[i] =0;
    }
    int dupCount=0;
    for(int i=size-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]==arr[j])
            {
                indArr[i] = 1;
                dupCount++;
            }
        }
    }
    int newArr[size-dupCount];
    int newArrIndex=0;
    for(int k=0;k<size;k++)
    {
        if(indArr[k]==0)
        {
            newArr[newArrIndex] = arr[k];
            newArrIndex++;
        }
    }
    cout<<"New Array is: ";
    for(int i=0;i<(size-dupCount);i++)
    {
        cout<<newArr[i]<<endl;
    }
}

int main() {
    int size = 9;
    int arr[size];
    cout<<"Enter Elements of Array with duplicates: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    prob4(arr,size);
    return 0;
}