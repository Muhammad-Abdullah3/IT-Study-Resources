#include<iostream>
#include<string>
using namespace std;

// pehle tu main simple class bana raha hun
class Students {
    private:
    //koi aik roll number hoga jo int type ka hoga
    int roll_number;
    //koi aik name hoga jo string type ka hoga
    string name;
    // aik marks ka array hoga jo float type ka hoga and hamare 6 subjects ke marks store 
    //karwayega
    float marks[6];
    public:
    // ab sab ke setter bana raha hun
    void setRollNumber() {
        cout<<"Enter Roll Number for Student: ";
        cin>>roll_number;
    }
    void setName() {
        cout<<"Enter Name of Student: ";
        cin.ignore();
        getline(cin,name);
    }
    void setMarks() {
        // Marks kis kis subjects ke honge: OOP, CAG, DLD, DSA, DB, COAL
        cout<<"Enter marks of a Student in Order: ";
        for(int i=0;i<6;i++)
        {
            cin>>marks[i];
        }
    }
    // get name aur get roll number wala function hoga
    int getRollNumber() {
        return roll_number;
    }
    string getName() {
        return name;
    }
    // ab ham marks wale array ko get karenge so that usko display kar saken
    float* getMarks() { //ab ye function mein ham apne array ke sabse pehle element ka address 
    //return karwayenge
    return marks;
    //ye function wese use nahi hota bas isko yahan explanation ke liye rakha hua
    }
    // ab ham display result ka aik function banayenge
    void displayResults() {
        cout<<"Roll Number: "<<getRollNumber()<<endl;
        cout<<"Name: "<<getName()<<endl;
        cout<<"\t\t\t\tMarks \t\t\t"<<endl;
        cout<<"OOP: "<<marks[0]<<endl;
        cout<<"CAG: "<<marks[1]<<endl;
        cout<<"DLD: "<<marks[2]<<endl;
        cout<<"DSA: "<<marks[3]<<endl;
        cout<<"DB: "<<marks[4]<<endl;
        cout<<"COAL: "<<marks[5]<<endl;
    }
};

int main() {
    // ab let's say ham chahte hain hamen section b ke 10 bachon ka result chahiye
    // ham sab ke object individual nahi banate aur bas aik array banate hain jismein 
    // sare 10 bachon ka result store hota hai
    // is Array ki Data Type class name hoga
    Students sectionB[3];// mene yahan sirf 3 bache liye hain
    // ab ham loop chala ke sab ke marks set karenge
    for(int i=0;i<3;i++) {
        sectionB[i].setRollNumber();
        sectionB[i].setName();
        sectionB[i].setMarks();
        // har index pe aik object hai Student class ka aur uski apni memory hai
        // jahan us object ka rollnumber,name, and uske 6 subjects ke marks hain
    }
    // ab ham loop chala ke sab student jo B section ke hain unka result aik aik karke
    // display karwa denge
    cout<<"Results of Sectio B students";
    for(int i=0;i<3;i++) {
        sectionB[i].displayResults();
    }
    return 0;
}