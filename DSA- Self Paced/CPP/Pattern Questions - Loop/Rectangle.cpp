/* Draw a rectangle Pattern
*****
*****
*****
*****
*****
*/
#include<iostream>
using namespace std;
int main()
{
	int rows = 0,col = 0;
	cout<<"Enter the number of Rows you want to Print: ";
	cin>>rows;
	cout<<"Enter the number of Coloumns you want to Print: ";
	cin>>col;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}