#include<iostream>
using namespace std;
int prob_8(int arr[],int size)
{
    int sum = arr[0];
    for(int i=0;i<size;i+=2)
    {
        sum = sum+arr[i];
    }
    return sum;
}
int main()
{
    
    return 0;
}