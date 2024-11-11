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
    void displayUsers() {
        for(int i=0;i<User::firstName.size();i++) {
            cout<<"User "<<i+1<<endl;
            cout<<"First Name"<<User::firstName[i]<<endl;
            cout<<"Last Name"<<User::lastName[i]<<endl;
            cout<<"University"<<User::university[i]<<endl;

        }
    }
};
vector<string> User::firstName;
vector<string> User::lastName;
vector<string> User::university;
vector<string> User::email;
vector<string> User::password;


int main() {
    User user;
    user.adduserCredentials("John","Doe","ABC University","john.doe@abcuni.com","asd5Av1$a#");
    user.adduserCredentials("Jane","Doe","ABC University","jane.doe@abcuni.com","sdQ4!ljiH31*&end");
    user.displayUsers();
    return 0;
}