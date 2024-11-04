#include<vector>
#include<iostream>
#include<string>
using namespace std;
class User {
    static vector<string> firstName;
    static vector<string> lastName;
    static vector<string> university;
    static vector<string> email;
    static vector<string> password;
    void adduserCredentials(string fName,string lName,string uni,string emai,string pass) {
        firstName.push_back(fName);
        lastName.push_back(lName);
        university.push_back(uni);
        email.push_back(emai);
        password.push_back(pass);
    }
};