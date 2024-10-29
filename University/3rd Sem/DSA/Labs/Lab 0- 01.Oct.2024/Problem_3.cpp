#include<iostream>
#include<string>
using namespace std;

string upperCase(string);
string lowerCase(string);
string titleCase(string);
int main()
{
	string name;
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Your name in upper case is: "<<upperCase(name)<<endl;
	cout<<"Your name in lower case is: "<<lowerCase(name)<<endl;
	cout<<"Your name in title case is: "<<titleCase(name)<<endl;
	return 0;
}

string upperCase(string name)
{
	int length =  name.length();
	for(int i=0;i<length;i++)
	{
		char c = name[i];
		name[i] = toupper(c);
	}
	return name;
}

string lowerCase(string name)
{
	int length =  name.length();
	for(int i=0;i<length;i++)
	{
		char c = name[i];
		name[i] = tolower(c);
	}
	return name;
}

string titleCase(string name)
{
	int length =  name.length();
	bool isNew = false;
	for(int i=0;i<length;i++)
	{
		//int index = 0;
		char c = name[i];
		if(i==0 && c!=' ')
		{
			if(c>='a' && c<='z')
			{
				name[i] = toupper(c);
			}
		}
		else if(isNew)
		{
			if(name[i]!=' '&& (c>='a' && c<='z'))
			{
				name[i] = toupper(c);
				
			}
			isNew=false;
		}
		else
		{
			if(c>='A' && c<='Z')
			{
				name[i] = tolower(c);
			}
			else if(c==' ')
			{
				isNew = true;
			}
		}
	}
	return name;
}