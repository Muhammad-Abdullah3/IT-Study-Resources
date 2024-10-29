#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// Creating a class
class Student {
    private:
    string name,uniName,className;
    int rollNum;
    public:
    // Default Constructor
    Student(): name (""),rollNum(0),uniName(""),className("") {}
    // Parameterized Constructor
    Student(string n, int r, string u, string c): name(n),rollNum(r),uniName(u),className(c) {}
    //Copy Constructor
    Student(Student &s): name(s.name),rollNum(s.rollNum),uniName(s.uniName),className(s.className) {}
    // Display Function of All Details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNum << endl;
        cout << "University Name: " << uniName << endl;
        cout << "Class Name: " << className << endl;
    }
};

int main() {
    // Creating an object of Student class with default Constructor
    Student s1;
    cout<<"\t\t\tDetails of Student 1"<<endl;
    s1.displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    // Creating an object of Student class with Parameterized Constructor
    Student* s2;
    s2 = new Student("Muhammad Abdullah", 53457, "Riphah International University", "DSA");
    cout<<"\t\t\tDetails of Student 2"<<endl;  
    s2->displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    // Creating an object of Student class with Copy Constructor
    Student s3;
    s3 = new Student(*s2);
    cout<<"\t\t\tDetails of Student 3"<<endl;
    s3->displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    getch();
    return 0;
}