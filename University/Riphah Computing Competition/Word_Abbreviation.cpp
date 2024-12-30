#include<iostream>
#include<string>
using namespace std;
int main(){
    string username;
    cout<<"Enter a word : ";
    getline(cin,username);
    int wordCount =0;
    for(int i=0;i<username.length();i++)
    {
            if(!(username.at(i)>='a'&&username.at(i)<='z'))
            {
                cout<<"Inccorrect Input";
                exit(0);
            }
            if(i!=0 && i !=username.length()-1)
            {
              wordCount++;   
            }
        
    }
    cout<<username.at(0)<<wordCount<<username.at(username.length()-1);
    return 0;
}