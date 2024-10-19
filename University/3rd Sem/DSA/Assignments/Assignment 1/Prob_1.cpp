#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
    private:
        string name;
        int rollNum;
        float marks;
    public:
        void setDetails() {
            string na;int ro;float ma;
            cout<<"Enter name: ";
            cin.ignore();
            getline(cin,na);
            name =na;
            cout<<"Enter roll number: ";
            cin>>ro;
            rollNum = ro;
            cout<<"Enter marks: ";
            cin>>ma;
            marks = ma;
        } 
        void displayDetails() {
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNum<<endl;
            cout<<"Marks: "<<marks<<endl;
        }
};
int main() {
    int n;
    vector<Student> stu;
    cout<<"Enter Number of Students: ";
    cin>>n;
    for(int i=0;i<n;i++) {
        cout<<"Enter Details for Student "<<i+1<<endl;
        stu.push_back(Student());
        stu[i].setDetails();
    }
    cout<<"\n\n\n\t\t\tDetails of Students\t\t\t"<<endl;
    for(int i=0;i<stu.size();i++) {
        cout<<"Details Student "<<i+1<<endl;
        stu[i].displayDetails();
    }
    return 0;
}