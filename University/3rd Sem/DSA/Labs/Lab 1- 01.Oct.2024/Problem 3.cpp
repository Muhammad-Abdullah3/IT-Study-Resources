#include<iostream>
#include<string>
using namespace std;

string uppercase(string);
int main()
{
	
	return 0;
}

string uppercase(string name)
{
	int length =  name.length();
	for(int i=0;i<length;i++)
	{
		char c = name[i];
		name[i] = c.toupper();
	}
	return string;
}