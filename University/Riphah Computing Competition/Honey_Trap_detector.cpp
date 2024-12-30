#include<iostream>
#include<string>
using namespace std;
int main(){
    string username;
    cout<<"Enter your username: ";
    getline(cin,username);
    int distinctCount =0;
    for(int i=0;i<username.length();i++)
    {
        for(int j=i+1;j<username.length();j++) {
            if(!((username.at(i)>='a'&&username.at(i)<='z')||(username.at(i)>='A'&&username.at(i)<='Z')))
            {
                cout<<"Inccorrect Input";
                exit(0);
            }
            if(!(username.at(i)==username.at(j)))
            {
              distinctCount++;   
            }
        }
    }
if(distinctCount%2==0){
    cout<<"Female";
}
else{
    cout<<"Male";
}
    return 0;
}