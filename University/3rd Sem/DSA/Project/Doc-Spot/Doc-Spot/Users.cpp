#include<vector>
#include<iostream>
#include<string>
using namespace std;
class User {
    private:
    static vector<string> firstName;
    static vector<string> lastName;
    static vector<string> university;
    static vector<string> email;
    static vector<string> password;
    public:
    void adduserCredentials(string fName,string lName,string uni,string emai,string pass) {
        firstName.push_back(fName);
        lastName.push_back(lName);
        university.push_back(uni);
        email.push_back(emai);
        password.push_back(pass);
    }
    // checking if the email is used or not
    bool isEmailUsed(string email) {
        int size = User::email.size();
        for(int i=0;i<size;i++) {
            if(email==User::email[i]) {
                return true;
            }
        }
        return false;
    }
    // checking if the account with this email is present or not
    bool isEmailpresent(string email) {
        int size = User::email.size();
        for(int i=0;i<size;i++) {
            if(email==User::email[i]) {
                return true;
            }
        }
        return false;
    }
    // Checking if the email and password are matched i.e successful login
    bool isLoginSuccessful(string email,string pass) {
        int size = User::email.size();
        int index = -1;
        for(int i=0;i<size;i++) {
            if(email==User::email[i]) {
                index = i;
                break;
            }
        }
        if(pass==User::password[index]) {
            return true;
        }
        else {
            return false;
        }
    }
};