#include<iostream>
using namespace std;
class Searching {
    public:
    void firstAndLast(int A[],int size,int target) {
        int occ[2];
        int count = 0;
        for(int i=0;i<size;i++) {
            if(count==1 && A[i]==target) {
                occ[1] = i;
            }
            else if(count==0 && A[i]==target) {
                occ[count]=i;
                count++;
            }
        }
        cout<<"First Occurence = "<<occ[0]<<"\nSecond Occurence = "<<occ[1];
    }

    int countOccurence(int A[],int size,int target) {
        int count = 0;
        for(int i=0;i<size;i++) {
            if(A[i]==target) {
                count++;
            }
        }
        return count;
    }

    //Check for Pairing Sum
    bool isTargetSum(int A[],int size,int targetSum) {
        for(int i=0;i<size;i++) {
            for(int j=i+1;j<size;j++) {
                if(A[i]+A[j]==targetSum) {
                    return true;
                }
            }
        }

    }
};
int main()
{
    int size = 6;
    int Arr[6] = {13,12,22,2,12,54};
    Searching search;
    search.firstAndLast(Arr,size,12);
    // Second Problm
    int size1 = 9;
    int Arr1[9] = {12,3,10,2,12,3,10,3,65};
    int target = 3;
    cout<<"\n\nTotal occurence of "<<target<<" = "<<search.countOccurence(Arr1,size1,target);
    // Third Problem
    int size2 = 7;
    int Arr2[7] = {5,2,12,3,10,87,65};
    int targetSum = 15;
    cout<<"\nTarget Sum Present: " <<search.isTargetSum(Arr2,size2,targetSum)? "True":"False";
    return 0;
}