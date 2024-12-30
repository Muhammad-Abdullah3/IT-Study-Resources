#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string num;
    cout<<"Enter your number Abel: ";
    getline(cin,num);
    // checking if number entered is correct or not and nearly lucky
    int luckyNumCount = 0;
    for(int i=0;i<num.length();i++)
    {
        if(!(num.at(i)>='0'&&num.at(i)<='9')) {
            cout<<"Incorrect Input";
            exit(0);
        }
        if((num.at(i)=='4'|| num.at(i)=='7')) {
           luckyNumCount++;
        }
    }
if((luckyNumCount==4)||(luckyNumCount==7)){
    cout<<"This number is nearly lucky number.";
}
else{
    cout<<"This number is not nearly lucky number.";
}
    return 0;
}