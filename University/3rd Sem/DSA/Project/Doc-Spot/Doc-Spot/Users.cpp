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
    // returning index of the account with this email 
    int isEmailpresent(string email) {
        int size = User::email.size();
        for(int i=0;i<size;i++) {
            if(email==User::email[i]) {
                return i;
            }
        }
        return -1;
    }
    // Checking if the email and password are matched i.e successful login
    bool isLoginSuccessful(string email,string pass,int index) {
        int size = User::email.size();
        if(pass==User::password[index]) {
            return true;
        }
        else {
            return false;
        }
    }
};