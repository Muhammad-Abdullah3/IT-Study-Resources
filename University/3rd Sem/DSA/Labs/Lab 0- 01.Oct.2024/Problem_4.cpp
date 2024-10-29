#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter an integer: ";
    cin>>x;
    if(x==0) {
        if(x==0) {
            cout<<"You entered zero.";
        }
        else if (x%2==0) {
            cout<<"You entered an even number.";
        }
        else {
            cout<<"You entered an odd number.";
        }
    }
    return 0;
}