#include<iostream>
using namespace std;
int main() {
    int rows = 0;
	cout<<"Enter the number of Rows you want to Print: ";
	cin>>rows;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
    return 0;
}