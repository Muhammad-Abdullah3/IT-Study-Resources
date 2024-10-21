#include<iostream>
#include<string>
using namespace std;

// is code mein ham friend function ko explain karenge
class Student {
    private:
    string name;
    public:
    void setName(string name) {
        // ham java mein this ke sath . ka operator lagate the, yhan ham arrow (->) 
        // operator lagayenge - aur > ko combine karke
        this->name = name;
    }
    string getName() {
        return name;
    }
    // yahan friend function nahi hai ye class ka apna function
    void display() {
        cout<<name<<" is not a friend."<<endl;
    }
    // friend function class ke andar define nahi hota hai
    // ham friend function ki prototype apni class mein hi banayenge
    friend void display(Student s);
};
// ab ham friend function ko define karenge
void display(Student s) {
    cout<<s.name<<" is a friend."<<endl;
}
// ab main function ka logic

int main() {
    Student s1,s2,s3;
    s1.setName("Muhammad Abdullah");
    s2.setName("Waheed Akhtar");
    s3.setName("Muhammad Ali");
    display(s1);
    display(s2);
    s3.display();
    return 0;

}